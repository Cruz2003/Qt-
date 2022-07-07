#include "enermyplane.h"
#include "config.h"

enermyPlane::enermyPlane()
{
    //陨石资源加载
    m_enemy.load(ENEMY_PATH);

    //陨石的位置
    m_X = 0;
    m_Y = 0;

    //陨石状态
    m_Free = true;

    //陨石速度
    m_Speed = ENEMY_SPEED;

    //陨石矩形框
    m_Rect.setWidth(m_enemy.width());
    m_Rect.setHeight(m_enemy.height());
    m_Rect.moveTo(m_X, m_Y);
}

void enermyPlane::updatePosition()
{
    if(m_Free){
        return;
    }


    m_Y += m_Speed;
    m_Rect  .moveTo(m_X, m_Y);

    //如果超出屏幕 重置空闲状态
    if(m_Y >= GAME_HEIGHT + m_Rect.height()){
        m_Free = true;
    }
}

