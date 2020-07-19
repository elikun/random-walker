#include "Environment.hpp"

Environment::Environment()
{
    std::cout << "== ENVIRONMENT LOADED ==" << std::endl;

    // Initialize environment map
    connectSignalsAndSlots();
    initEnvironmentMap();
    m_graph.init(CONFIG_INI_FILE);
    loadGraphEdges();
    spawnDotObject();

    // Start command receiver thread
    m_envCmdRcv = new CommandReceiver(ENVIRONMENT_PORT);
    m_envCmdRcv->startCommandReceive(m_envCmdQueue);
}

Environment::~Environment()
{
}

void Environment::displayCommandFromQueue()
{
    int cmd = -1;
    while(true) {
        cmd = m_envCmdQueue.pop_front();
        if (m_graph.isValidMovement(cmd)) {
            switch (cmd) {
                case 0: emit MoveUpSignal();    break;
                case 1: emit MoveDownSignal();  break;
                case 2: emit MoveLeftSignal();  break;
                case 3: emit MoveRightSignal(); break;
                default: break;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(MOVEMENT_DURATION_MS + MOVEMENT_INTERVAL_MS));
        }
    }
}

void Environment::connectSignalsAndSlots()
{
    QObject::connect(this, SIGNAL(MoveUpSignal()),    &this->m_dotObject, SLOT(moveUp()));
    QObject::connect(this, SIGNAL(MoveDownSignal()),  &this->m_dotObject, SLOT(moveDown()));
    QObject::connect(this, SIGNAL(MoveLeftSignal()),  &this->m_dotObject, SLOT(moveLeft()));
    QObject::connect(this, SIGNAL(MoveRightSignal()), &this->m_dotObject, SLOT(moveRight()));
}

void Environment::initEnvironmentMap()
{
    // Remove border of view
    m_view.setStyleSheet("border: 0px");

    // Add scene
    m_scene = new QGraphicsScene(0, 0, SCREEN_SIZE, SCREEN_SIZE);
    m_scene->setBackgroundBrush(Qt::black);

    // Add title header
    QFont font;
    font.setPointSize(TITLE_FONT_SIZE);
    QGraphicsTextItem *text = m_scene->addText("2D RANDOM WALK", font);
    text->setPos(TITLE_POSITION_X, TITLE_POSITION_Y);
    text->setDefaultTextColor(Qt::white);
    text->setFont(font);

    // Put axis labels
    font.setPointSize(AXIS_LABEL_FONT_SIZE);
    std::string xyLabel;
    for (int j = 0; j < ENVIRONMENT_MAP_SIZE; j++) {
        for (int i = 0; i < ENVIRONMENT_MAP_SIZE; i++) {
            xyLabel = std::to_string(i) + std::to_string(j);
            text = m_scene->addText(QString(xyLabel.c_str()));
            text->setPos(AXIS_LABEL_ORIGIN_X + i * MOVEMENT_STEP, AXIS_LABEL_ORIGIN_Y + j * MOVEMENT_STEP);
            text->setDefaultTextColor(Qt::green);
            text->setFont(font);
        }
    }

    // View the created scene
    m_view.setScene(m_scene);
    m_view.resize(SCREEN_SIZE, SCREEN_SIZE);
    m_view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_view.show();
}

void Environment::loadGraphEdges()
{
    std::vector<Edge> edges = m_graph.getEdges();

    QPen pen(Qt::blue, 4, Qt::SolidLine);
    for (std::vector<Edge>::iterator it = edges.begin(); it != edges.end(); ++it) {
        m_scene->addLine(ENVIRONMENT_ORIGIN_X + ((*it).getV1() / 10) * MOVEMENT_STEP, // x1
                         ENVIRONMENT_ORIGIN_Y + ((*it).getV1() % 10) * MOVEMENT_STEP, // y1
                         ENVIRONMENT_ORIGIN_X + ((*it).getV2() / 10) * MOVEMENT_STEP, // x2
                         ENVIRONMENT_ORIGIN_Y + ((*it).getV2() % 10) * MOVEMENT_STEP, // y2
                         pen);
    }
}

void Environment::spawnDotObject()
{
    m_scene->addItem(&m_dotObject);
    m_dotObject.setRect(ENVIRONMENT_ORIGIN_X - DOT_RADIUS, ENVIRONMENT_ORIGIN_Y - DOT_RADIUS, DOT_DIAMETER, DOT_DIAMETER);
    m_dotObject.setBrush(Qt::yellow);
}
