#ifndef AVR_PROTO_LINUX_FILERWPLUGIN_H
#define AVR_PROTO_LINUX_FILERWPLUGIN_H

#include "FileEntity.h"
#include "AbstractPlugin.h"
#include "AbstractReadDriver.h"
#include <fcntl.h>
#include "AbstractWriteDriver.h"
#include <sys/stat.h>
#include "UndefinedFileException.h"


//todo Сделать Контроллер процессов которые будет понимать какой процесс каким файлом пользуется
class FileController {
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
            this->throwErrnoException(filePath);
        }
        return new FileEntity(fileIndex, flag, readDriver, writeDriver);
    }

    int getErrno() {
        return errno;
    }

    void throwErrnoException(std::string filePath) {
        switch (errno) {
            case EPERM:
                throw ConfigurateException("Operation not permitted: "+filePath);
                break;
            case ENOENT:
                throw ConfigurateException("No such file or directory: "+filePath);
                break;
            case ESRCH:
                throw ConfigurateException("No such process: "+filePath);
                break;
            case EINTR:
                throw ConfigurateException("Interrupted system call: "+filePath);
                break;
            case EIO:
                throw ConfigurateException("I/O error: "+filePath);
                break;
            case ENXIO:
                throw ConfigurateException("No such device or address: "+filePath);
                break;
            case E2BIG:
                throw ConfigurateException("Argument list too long: "+filePath);
                break;
            case ENOEXEC:
                throw ConfigurateException("Exec format error: "+filePath);
                break;
            case EBADF:
                throw ConfigurateException("Bad file number: "+filePath);
                break;
            case ECHILD:
                throw ConfigurateException("No child processes: "+filePath);
                break;
            case EAGAIN:
                throw ConfigurateException("Try again: "+filePath);
                break;
            case ENOMEM:
                throw ConfigurateException("Out of memory: "+filePath);
                break;
            case EACCES:
                throw ConfigurateException("Permission denied: "+filePath);
                break;
            case EFAULT:
                throw ConfigurateException("Bad address: "+filePath);
                break;
            case ENOTBLK:
                throw ConfigurateException("Block device required: "+filePath);
                break;
            case EBUSY:
                throw ConfigurateException("Device or resource busy: "+filePath);
                break;
            case EEXIST:
                throw ConfigurateException("File exists: "+filePath);
                break;
            case EXDEV:
                throw ConfigurateException("Cross-device link: "+filePath);
                break;
            case ENODEV:
                throw ConfigurateException("No such device: "+filePath);
                break;
            case ENOTDIR:
                throw ConfigurateException("Not a directory: "+filePath);
                break;
            case EISDIR:
                throw ConfigurateException("Is a directory: "+filePath);
                break;
            case EINVAL:
                throw ConfigurateException("Invalid argument: "+filePath);
                break;
            case ENFILE:
                throw ConfigurateException("File table overflow: "+filePath);
                break;
            case EMFILE:
                throw ConfigurateException("Too many open files: "+filePath);
                break;
            case ENOTTY:
                throw ConfigurateException("Not a typewriter: "+filePath);
                break;
            case ETXTBSY:
                throw ConfigurateException("Text file busy: "+filePath);
                break;
            case EFBIG:
                throw ConfigurateException("File too large: "+filePath);
                break;
            case ENOSPC:
                throw ConfigurateException("No space left on device: "+filePath);
                break;
            case ESPIPE:
                throw ConfigurateException("Illegal seek: "+filePath);
                break;
            case EROFS:
                throw ConfigurateException("Read-only file system: "+filePath);
                break;
            case EMLINK:
                throw ConfigurateException("Too many links: "+filePath);
                break;
            case EPIPE:
                throw ConfigurateException("Broken pipe: "+filePath);
                break;
            case EDOM:
                throw ConfigurateException("Math argument out of domain of func: "+filePath);
                break;
            case ERANGE:
                throw ConfigurateException("Math result not representable: "+filePath);
                break;
            default:
                throw ConfigurateException("Unknown error: "+filePath);
        }
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
};

#endif
