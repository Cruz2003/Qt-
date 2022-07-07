#include "mainwscene.h"
#include "config.h"
#include <QIcon>
#include <QPainter>
#include <QMouseEvent>
#include <ctime>

MainWScene::MainWScene(QWidget *parent)
    : QWidget(parent)
{
    //调用初始化场景
    initScene();
    //启动游戏
    playGame();
}

MainWScene::~MainWScene()
{
}

void MainWScene::initScene()
{
    //设置窗口固定尺寸
    setFixedSize(GAME_WIDTH, GAME_HEIGHT);

    //设置标题
    setWindowTitle(GAME_TITLE);

    //加载图标
    setWindowIcon(QIcon(GAME_ICON));

    //定时器设置
    m_Timer.setInterval(GAME_RATE);

    //陨石出场时间间隔 初始化
    m_recorder = 0;

    //随机数种子
    srand((unsigned int)time(NULL));
}

void MainWScene::playGame()
{
    //启动定时器
    m_Timer.start();

    //监听定时器发送的信号
    connect(&m_Timer , &QTimer::timeout, [=](){
        //陨石出场
        enemyToScene();
        //更新游戏中的元素
        updatePosition();
        //绘制到屏幕中
        update();
        //碰撞检测
        collisionDetection();
    });
}

void MainWScene::updatePosition()
{
    //更新地图坐标
    m_map.mapPosition();

    //陨石出场
    for(int i = 0; i < ENEMY_NUM; i++){
        if(m_enemys[i].m_Free == false){
            m_enemys[i].updatePosition();
        }
    }

}

void MainWScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //绘制地图
    painter.drawPixmap(0, m_map.m_map1_posY, m_map.m_map1);
    painter.drawPixmap(0, m_map.m_map2_posY, m_map.m_map2);

    //绘制英雄飞机
    painter.drawPixmap(m_hero.m_X, m_hero.m_Y, m_hero.m_Plane);

    //绘制陨石
    for(int i = 0; i < ENEMY_NUM; i++){
        if(m_enemys[i].m_Free == false){
            painter.drawPixmap(m_enemys[i].m_X, m_enemys[i].m_Y, m_enemys[i].m_enemy);
        }
    }
}


void MainWScene::keyPressEvent(QKeyEvent *event)
{
    //判断按下哪个按键，并打上标记
    if(event->key() == Qt::Key_Up)
        m_hero.m_Y -= HERO_SPEED;
    if(event->key() == Qt::Key_Down)
        m_hero.m_Y += HERO_SPEED;
    if(event->key() == Qt::Key_Left)
        m_hero.m_X -= HERO_SPEED;
    if(event->key() == Qt::Key_Right)
        m_hero.m_X += HERO_SPEED;
    //边界检测
    if(m_hero.m_X <= 0 )
    {
       m_hero.m_X = 0;
    }
    if(m_hero.m_X >= GAME_WIDTH - m_hero.m_Rect.width())
    {
       m_hero.m_X = GAME_WIDTH - m_hero.m_Rect.width();

    }
    if(m_hero.m_Y <= 0)
    {
       m_hero.m_Y = 0;

    }
    if(m_hero.m_Y >= GAME_HEIGHT - m_hero.m_Rect.height())
    {
       m_hero.m_Y = GAME_HEIGHT - m_hero.m_Rect.height();

    }
    m_hero.setPosition(m_hero.m_X, m_hero.m_Y);
}

void MainWScene::enemyToScene()
{
    m_recorder++;
    //未达到出场间隔，直接return
    if(m_recorder < ENEMY_INIERVAL){
        return;
    }
    m_recorder = 0;

    for(int i = 0; i < ENEMY_NUM; i++){
        //如果是空闲陨石 出场
        if(m_enemys[i].m_Free){
            m_enemys[i].m_Free = false;

            //坐标
            m_enemys[i].m_X = rand()%(GAME_WIDTH - m_enemys[i].m_Rect.width());
            m_enemys[i].m_Y = -m_enemys[i].m_Rect.height();
            break;
        }
    }
}

void MainWScene::collisionDetection()
{
    //遍历所有非空闲的陨石
    for(int i = 0; i < ENEMY_NUM; i++){
        if(m_enemys[i].m_Free){
            continue;
        }
        //飞机撞到陨石就会回到起点 陨石会消失
        if(m_enemys[i].m_Rect.intersects(m_hero.m_Rect)){
            m_hero.resetPosition();
            m_enemys[i].m_Free = true;
        }
    }

}

