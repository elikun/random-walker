#ifndef ENVIRONMENT_CLASS_H
#define ENVIRONMENT_CLASS_H

#include <QAbstractAnimation>
#include <QApplication>
#include <QFont>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QPen>
#include <QPropertyAnimation>
#include <QRect>
#include <QString>
#include <QThread>

#include <iostream>
#include <chrono>
#include <fstream>
#include <thread>
#include <string>

#include "../Common/MDL_CommandQueue/CommandQueue.hpp"
#include "../Common/MDL_CommandReceiver/CommandReceiver.hpp"
#include "EnvironmentConstants.hpp"
#include "MDL_Dot/Dot.hpp"
#include "MDL_Edge/Edge.hpp"
#include "MDL_Graph/Graph.hpp"

class Environment : public QObject
{
    Q_OBJECT

    public:
        Environment();
        ~Environment();

    signals:
        void MoveUpSignal();
        void MoveDownSignal();
        void MoveLeftSignal();
        void MoveRightSignal();

    public slots:
        void displayCommandFromQueue();

    private:
        void connectSignalsAndSlots();
        void initEnvironmentMap();
        void loadGraphEdges();
        void spawnDotObject();

        CommandQueue m_envCmdQueue;
        CommandReceiver *m_envCmdRcv;
        QGraphicsView m_view;
        QGraphicsScene *m_scene;
        Graph m_graph;
        Dot m_dotObject;
};

#endif
