#ifndef MAINWSCENE_H
#define MAINWSCENE_H

#include <QWidget>
#include <QTimer>
#include "map.h"
#include "heroplane.h"
#include "enermyplane.h"
#include "config.h"


class MainWScene : public QWidget
{
    Q_OBJECT

public:
    MainWScene(QWidget *parent = nullptr);
    ~MainWScene();

    //初始化场景
    void initScene();

    //启动游戏
    void playGame();

    //更新所有游戏中元素的坐标
    void updatePosition();

    //绘制到屏幕中 函数名称不可改；
    void paintEvent(QPaintEvent *);

    //重写键盘事件 函数名不可变
    void keyPressEvent(QKeyEvent * event);

    //陨石出场
    void enemyToScene();

    //陨石数组
    enermyPlane m_enemys[ENEMY_NUM];

    //陨石出场间隔
    int m_recorder;

    //地图对象
    Map m_map;

    //飞机对象
    HeroPlane m_hero;

    //定时器
    QTimer m_Timer;

    //判断陨石和飞机是否碰撞
    void collisionDetection();
};
#endif // MAINWSCENE_H
