#include "task.h"

Task::Task(QObject *parent) :
    QObject(parent)
{
}

void Task::run()
{
    // Do processing here

    qDebug()<<"Hello!";

    emit finished();
}
