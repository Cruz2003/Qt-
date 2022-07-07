#ifndef CONFIG_H
#define CONFIG_H
/********游戏配置数据********/

#define GAME_WIDTH 512 //宽度
#define GAME_HEIGHT 768 //高度
#define GAME_TITLE "陨石撞飞机v1.0" //游戏标题
#define GAME_RES_PATH "./plane.rcc" //游戏路径
#define GAME_ICON ":/res/icon01.png" //图标路径
#define GAME_RATE 15 //定时器刷新时间间隔 单位是毫秒


/********地图配置数据********/
#define MAP_PATH ":/res/map05.jpg" //地图路径
#define MAP_SCROLL_SPEED 3 //地图滚动速度

/********飞机配置数据********/
#define HERO_PATH ":/res/bad04.png" //飞机图片路径
#define HERO_SPEED 20 //设置飞机移动速度

/********陨石配置数据********/
#define ENEMY_PATH ":/res/blt03.png"
#define ENEMY_SPEED 5 //陨石资源图片
#define ENEMY_NUM 15  //陨石总数量
#define ENEMY_INIERVAL 40 //陨石出场时间间隔 单位毫秒

/********音乐配置数据*******/
//#define BACKGROUND_PATH ":/res/socute.wav" 放弃背景音乐了

#endif // CONFIG_H
