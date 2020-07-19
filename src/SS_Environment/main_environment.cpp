#include "Environment.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Environment *env = new Environment();
    QThread *envUIThread = new QThread();
    QObject::connect(envUIThread, SIGNAL(started()), env, SLOT(displayCommandFromQueue()));
    QObject::connect(envUIThread, SIGNAL(finished()), env, SLOT(deleteLater()));
    env->moveToThread(envUIThread);
    envUIThread->start();

    return app.exec();
}
