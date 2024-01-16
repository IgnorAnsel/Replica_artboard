#pragma once
#include"comment.h"
void uishow();//展示界面
void Freedrawing();//自由画画
void Fill();//颜色填充
void ResetColorRed();//滑条改变R颜色
void ResetColorGreen();//滑条改变G颜色
void ResetColorBlue();//滑条改变B颜色
void xylocation();//显示鼠标xy的坐标值
void ResetColor();//滑条改变RGB颜色
void SetColor();//选择设置已有颜色
void SetMyColor();//选择设置自己保存的颜色
void Resetlinestyle();//改变画笔的样式
void linethickness();//改变画笔粗细大小
void MouseChange();//不断获取前一个mouse的xy
void avoidbug();//防止弹出继续画图
void menu();//主要功能
void clean();//橡皮檫
void allclean();//清空画布
void drawline();//直线的绘制
void drawbox();//矩形绘制
void formchose();//用于图形绘制的选择
void draws();//用于绘制圆弧
void drawellipse();//用于绘制椭圆
int radiuss(int x, int y, int bx, int by);//计算两点之间距离（求半径）
void drawcircle();//用于绘制圆
void getColor();//获取颜色
void save();//保存你自己的颜色
void load();//加载你保存好的颜色
void drawsector();//画扇形
void saveimage();//保存你的绘图
void resetr();//设置角度
void explan();//进入说明界面
void openimg();//  打开图片






