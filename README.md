# The Travis Client [![Build Status](https://travis-ci.org/Michael355/lab09.svg?branch=master)](https://travis-ci.org/travis-ci/lab09)

![The Travis Mascot](http://about.travis-ci.org/images/travis-mascot-200px.png)

## Laboratory work IX

Данная лабораторная работа посвещена изучению процесса создания пакета на примере **Github Release**

```ShellSession
$ open https://help.github.com/articles/creating-releases/
```

## Tasks

- [X] 1. Создать публичный репозиторий с названием **lab09** на сервисе **GitHub**
- [X] 2. Ознакомиться со ссылками учебного материала
- [X] 3. Получить токен для доступа к репозиториям сервиса **GitHub**
- [X] 4. Сгенерировать GPG ключ и добавить его к аккаунту сервиса **GitHub**
- [X] 5. Выполнить инструкцию учебного материала
- [X] 6. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

## Tutorial
Установим значения GITHUB_USERNAME и GITHUB_TOKEN
```ShellSession
$ export GITHUB_TOKEN=XxX # Установка значения полученного токена
$ export GITHUB_USERNAME=Michael355 # Установка значения GITHUB_USERNAME
$ alias gsed=sed # for *-nix system
```
Cкачиваем предыдущую лабораторную работу в папку lab09.
```ShellSession
$ git clone https://github.com/Michael355/lab08 lab09 # Загружаем гит в папку lab09
$ cd lab09 # Переходим в папку lab09
$ git remote remove origin # Очищаем старый путь загрузки гита
$ git remote add origin https://github.com/Michael355/lab09 # Устанавливаем новый путь загрузки гита
```
В файле README.md в строке заменяем lab08 на lab09
```ShellSession
$ gsed -i 's/lab08/lab09/g' README.md # Заменяем lab08 на lab09
```

```ShellSession
$ cmake -H. -B_build -DCPACK_GENERATOR="TGZ" # Задаем архивирование в tar.gz
$ cmake --build _build --target package # Архивируем
``` 
Авторизация travis и подключение lab09 к travis.
```ShellSession
$ travis login --auto # Процесс авторизации без токена
$ travis enable # Подключаем lab09 к travis'у
```
```ShellSession
$ git tag -s v0.1.0.0 # Подписываем v0.1.0.0
$ git tag -v v0.1.0.0 # Проверяем подписку
$ git push origin master --tags # Пушим изменения под v0.1.0.0
```
```ShellSession
$ github-release --version # Версия github-release
$ github-release info -u ${GITHUB_USERNAME} -r lab09 # Информация о релизе lab09
$ github-release release \ # Пишем информацию о релизе
    --user ${GITHUB_USERNAME} \
    --repo lab09 \
    --tag v0.1.0.0 \
    --name "libprint" \
    --description "my first release"
```
Устанавливаем две переменных PACKAGE_OS и PACKAGE_ARCH, загружаем релиз на сервер.
```ShellSession
$ export PACKAGE_OS=`uname -s` PACKAGE_ARCH=`uname -m`  # Переменные окружений PACKAGE_OS и PACKAGE_ARCH 
$ export PACKAGE_FILENAME=print-${PACKAGE_OS}-${PACKAGE_ARCH}.tar.gz # Переменная окружения PACKAGE_FILENAME
$ github-release upload \ # Загружаем релиз на GitHub
    --user ${GITHUB_USERNAME} \
    --repo lab09 \
    --tag v0.1.0.0 \
    --name "${PACKAGE_FILENAME}" \
    --file _build/*.tar.gz
```
```ShellSession
$ github-release info -u ${GITHUB_USERNAME} -r lab09 # Обновленная информация о релизе lab09
$ wget https://github.com/${GITHUB_USERNAME}/lab09/releases/download/v0.1.0.0/${PACKAGE_FILENAME} # Скачиваем файл
$ tar -ztf ${PACKAGE_FILENAME} # Распаковываем файл
```
## Report
```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=09
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```
## Report

```ShellSession
$ popd
$ export LAB_NUMBER=09
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Links

- [Create Release](https://help.github.com/articles/creating-releases/)
- [Get GitHub Token](https://help.github.com/articles/creating-a-personal-access-token-for-the-command-line/)
- [Signing Commits](https://help.github.com/articles/signing-commits-with-gpg/)
- [Go Setup](http://www.golangbootcamp.com/book/get_setup)
- [github-release](https://github.com/aktau/github-release)

```
Copyright (c) 2017 Братья Вершинины
```
