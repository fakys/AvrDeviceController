# AvrDeviceController
Демон для linux для контроля ваших девайсов с микроконтроллерами архитектуры avr      

## Компиляция
```shell
cmake -DPLUGINS="HttpClientPlugin;AvrDevicesPlugin" -S ./ -B ./build/
```

## Конфигурация
По умолчанию смотрит на путь `/etc/avr_device_controller/main.conf` но базовый путь можно переопределить при компиляции через ключ `_PROJECT_CONFIG_PATH_`.

Так же можно задаит задать путь к конфигу при запуске передав ключ `--config_path=путь/до/конфига` ну или в сокращенном варианте `-conf=путь/до/конфига`

Пример файла конфигурации 
```
config = {
        error_log_path = /etc/avr_device_controller/error.log;
        accept_log_path = /etc/avr_device_controller/accept.log;
        devices = [
                {
                        name = device_1;
                        type = UART;
                        path = /dev/ttyUSB0;
                }
                {
                        name = device_2;
                        type = UART;
                        path = /dev/ttyUSB1;
                }
        ]
}
```
Название ключей строгое, пробелы в путях к файлам недопустимы, все пути должны идти неразрывной строкой

## Веб сервер
Если добавить плагин HttpClientPlugin то появится возможность связываться с демоном по http

Для этого используется специальный сервер Crow, сслыка на GitHub - https://github.com/CrowCpp/Crow
