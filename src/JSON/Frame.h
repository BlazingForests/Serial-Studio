/*
 * Copyright (c) 2020-2021 Alex Spataru <https://github.com/alex-spataru>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef JSON_FRAME_H
#define JSON_FRAME_H

#include <QVector>
#include <QObject>
#include <QVariant>
#include <QJsonArray>
#include <QJsonObject>

#include "Group.h"

namespace JSON
{
class Frame : public QObject
{
    // clang-format off
    Q_OBJECT
    Q_PROPERTY(QString title
               READ title
               CONSTANT)
    Q_PROPERTY(int groupCount
               READ groupCount
               CONSTANT)
    Q_PROPERTY(QVector<Group*> groups
               READ groups
               CONSTANT)
    // clang-format on

public:
    Frame(QObject *parent = nullptr);
    ~Frame();

    void copy(Frame *frame);

    void clear();
    QString title() const;
    int groupCount() const;
    QVector<Group *> groups() const;
    bool read(const QJsonObject &object);
    Q_INVOKABLE Group *getGroup(const int index);

private:
    QString m_title;
    QVector<Group *> m_groups;
};
}
#endif
