#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QDebug>

class Task : public QObject
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = 0);

signals:
    void finished();

public slots:
    void run();
};

#endif // TASK_H
