#pragma once
#include"comment.h"
#define PI 3.1415926535//定义PI
ExMessage mouse;//鼠标定义
int isdown;//鼠标按下与否
int mousex, mousey;//在绘图区记录mouse坐标
int bmousex, bmousey;//在画直线扇形等中记录mouse的起点
int emousex, emousey;//在功能区记录mouse的坐标
int cc,cc1;
int x = 0;//R变量
int y = 0;//G变量
int z = 0;//B变量
double r1 = 0,r2= 0;//弧度值
double r;//储存设置好的r值
int exchangel = 1, exchanger = 1,exchangeu=1,exchanged=1;//扇形圆弧的方向改变
TCHAR s[10];//
int functionnum = -100;//存储按下功能后的值
int penstyle = 1;//储存画笔的类型
int linethick = 2;//储存画笔粗细
int colornum = -100;//暂定的颜色选择
int colorsure = -100;//确定颜色
int mycolornum = -100;//暂定自己的颜色选择
int mycolorsure = -100;//确定自己的颜色
int formnum=-100;//储存样式选择框
int formsure=-100;//确定图形样式
int count = 0;//一直停留计数
int ellimask=-1;//实现画椭圆起始点问题的遮盖



