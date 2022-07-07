#ifndef ENERMYPLANE_H
#define ENERMYPLANE_H
#include <QPixmap>

class enermyPlane
{
public:
    enermyPlane();
    //更新坐标
    void updatePosition();


public:

    //陨石资源对象
    QPixmap m_enemy;

    //位置
    int m_X;
    int m_Y;

    //陨石的矩形边框（碰撞检测）
    QRect m_Rect;

    //状态
    bool m_Free;

    //速度
    int m_Speed;
};

#endif // ENERMYPLANE_H

