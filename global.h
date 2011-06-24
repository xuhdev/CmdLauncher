/*
 * CmdLauncher
 *
 * Copyright (c) 2011 Hong Xu
 *
 *
 * This file is part of CmdLauncher.
 *
 * CmdLauncher is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 * 
 * CmdLauncher is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with CmdLauncher. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GLOBAL_H
#define GLOBAL_H

#include <QHash>
#include <QList>
#include <QString>
#include <QStringList>
#include <QVariant>

class Global
{
private:
    Global();

public:
    typedef QHash<QString, QVariant> Item;

    static Global* getInstance();

    // terminal information
    struct Terminal
    {
        QString name;
        QString cmd;
    };

    struct About
    {
        QString name;
        QString description;
        QStringList authors;
        QString url;
        QString pixmapFile;
    };

private:
    QString iniFile;
    QString windowTitle;
    QString command;
    QStringList tabs;
    QList<Global::Item*> items;
    QList<Global::Terminal*> terminals;
    Global::About about;

public:
    const QList<Global::Item*>* getItems();
    const QString* getCommand();
    const QStringList* getTabs();
    const QString* getWindowTitle();
    const QList<Global::Terminal*>* getTerminals();
    const Global::About* getAbout();
    void setItemTabpageRow(int index, int tabpage, int row);
};

#endif // GLOBAL_H
