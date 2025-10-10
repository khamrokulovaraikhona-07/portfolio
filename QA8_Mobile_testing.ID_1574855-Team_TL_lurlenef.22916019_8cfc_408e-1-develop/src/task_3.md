# Задание 3. Работа с Android Studio

## 1. Установка Android Studio  
[Официальный сайт](https://developer.android.com/studio)  
- Установлено через официальный сайт.  
- Выбран стандартный тип установки.  
- SDK установлен в `/home/lurlenef/Android/Sdk`.

## 2. Создание эмулятора  
> При попытке создать AVD возникла ошибка:  
An error occurred while creating the AVD. See idea.log for details.  
Проверено: поддержка виртуализации включена (vmx).  
Установленные пакеты:  
bash sudo apt install qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils virt  
manager sudo adduser $USER kvm sudo adduser $USER libvirt  
Перезагрузка выполнена. Планируется повторная попытка создания AVD.

- ## АВТОРЫ - lurlenef , jammieas

## 3. Режим разработчика (эмулятор)  
Включён через: Settings → About phone → Build number (7 раз).  
USB Debugging включен в Developer options.

## 4. Logcat  
Logcat использован для просмотра логов приложения.  
Применены фильтры: **ActivityManager, System.err.**

## 5. Создание эмулятора в Xcode (macOS)  
Установка Xcode.  
Переход: **Xcode → Settings → Components — iOS** загрузить.  
Открыть: **Window → Devices and Simulators.**  
Во вкладке Simulators: **+ → выбрать модель и версию.**  
- Нажать кнопку **Create.**

- ## АВТОРЫ - lurlenef , jammieas
