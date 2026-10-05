#ifndef AVR_PROTO_LINUX_FILERWPLUGIN_H
#define AVR_PROTO_LINUX_FILERWPLUGIN_H

#include "FileEntity.h"
#include "AbstractReadDriver.h"
#include <fcntl.h>
#include "AbstractWriteDriver.h"
#include <sys/stat.h>
#include "UndefinedFileException.h"


class FileRWPlugin: public AbstractPlugin {
    private:
        //Вектор с открытыми файлами
        std::vector<FileEntity*> files;
    public:
    //Открываем файл указывая драйвера для чтения и записи
    FileEntity* openFile(std::string filePath, AbstractReadDriver* readDriver = nullptr, AbstractWriteDriver* writeDriver = nullptr) {
        //Если драйвера для чтения и записи небыли переданны то создаем файл
        int flag = O_EXCL;
        if (readDriver && !writeDriver) {
            flag = O_RDONLY;
        } else if (readDriver && writeDriver) {
            flag = O_RDWR;
        } else if (!readDriver && writeDriver) {
            flag = O_WRONLY;
        }

        int fileIndex = open(&filePath[0], flag);
        if (fileIndex < 0) {
            return nullptr;
        }
        return new FileEntity(fileIndex, flag, readDriver, writeDriver);
    }

    bool checkAccessFile(std::string filePath) {
        struct stat buffer;
        if (stat(&filePath[0], &buffer) == 0) {
            if (!S_ISREG(buffer.st_mode)) {
                throw FileErrorException("Path "+filePath+" is not a file", errno);
            }
            return true;
        } else {
            if (errno == ENOENT) {
                throw UndefinedFileException("file "+filePath+" not found");
            } else {
                throw FileErrorException("fail to check file "+filePath, errno);
            }
        }
    }

    std::string getPluginName() override {
        return "FileRWPlugin";
    };

    int pluginLoad() override {
        return 0;
    }

    std::vector<std::string>* getDependPlugins() override {
        return nullptr;
    }
};

#define FileRWP "FileRWPlugin"

#endif
