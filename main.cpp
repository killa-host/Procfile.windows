#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <sys/utsname.h>
#include <cassert>

using namespace std;

void PrintKernelInfo();

int main()
{   
    
    PrintKernelInfo();

    cout << "2. Тип и роль узла:" << endl;
    system("hostname");
    system("nslookup localhost");
    system("netstat -lpn");

    cout << "3. Установленные обновления:" << endl;
    system("cat /etc/os-release");
    system("cat /var/lib/apt/extended_states");

    cout << "4. Политика учетных записей:" << endl;
    system("w");
    system("cat /etc/passwd");

    cout << "Администраторы" << endl;
    system("cat /etc/group | grep root");

    cout << "Список активных пользователей" << endl;
    system("who");

    cout << "Групповые политики:" << endl;
    system("cat /etc/group");

    cout << "5. Политика паролей:" << endl;
    system("cat /etc/pam.d/common-password");

    cout << "6. Аудит:" << endl;
    system("cat /etc/pam.d/runuser");

    cout << "ACPI" << endl;
    system("ls -l /etc/UPower/UPower.conf");
    cout << "ALSA" << endl;
    system("ls -l /etc/alsa/conf.d");


    cout << "7. Сетевые настройки:" << endl;
    system("ifconfig");

    cout << "Таблица маршрутизации" << endl;
    system("netstat -at");

    cout << "8. Запущенные сервисы:" << endl;
    system("rc-status -a");

    cout << "Активные процессы:" << endl;
    system("ps -ef");

    cout << "9. Файловая система:" << endl;
    system("df");

    cout << "Тип файловой системы:" << endl;
    system("blkid");

    cout << "Права доступа к важным каталогам:" << endl;
    system("ls /etc -l");

    cout << "10. Групповые политики:" << endl;
    system("cat /etc/group");

    cout << "11. Пароли и шифрование:" << endl;
    system("cat /etc/shadow");

    cout << "12. Анализ лог:" << endl;
    system("dir  /var/log/");

    cout << "13. Открытые порты:" << endl;
    system("netstat -l");

}

void PrintKernelInfo()
{
    cout << "1. Вид ОС:" << endl;
    system("uname");
    utsname kernelInfo;
    const int code = uname(&kernelInfo);
    assert(code == 0); (void)code;

    std::printf("-- Kernel info --\n"
                "  domainname=%s\n"
                "  machine=%s\n"
                "  nodename=%s\n"
                "  release=%s\n"
                "  sysname=%s\n"
                "  version=%s\n",
                kernelInfo.domainname,
                kernelInfo.machine,
                kernelInfo.nodename,
                kernelInfo.release,
                kernelInfo.sysname,
                kernelInfo.version);
}
