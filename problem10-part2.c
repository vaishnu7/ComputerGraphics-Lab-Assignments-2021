#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<process.h>

int cx=250,cy=90,r=300;
int x=0,y,p;

int path(int dtn) {
	int x1,y1;
	setcolor(15);
	if(x>=y) {
		return 0;
	}

	cleardevice();

	if(dtn==1) {
		circle(cx+x,cy+y,50);
		line(cx,cy,cx+x,cy+y);
	} 
            else {
		circle(cx-x,cy+y,50);
		line(cx,cy,cx-x,cy+y);
	}

	delay(1);

	if(kbhit())
	        exit(0);
	x++;

	if(p<0)
	        p+=2*x+1; 

           else {
		y--;
		p+=2*(x-y)+1;
	}

	x1=x;
	y1=y;
	path(dtn);

	cleardevice();

	if(dtn==1) {
		circle(cx+x1,cy+y1,50);
		line(cx,cy,cx+x1,cy+y1);
	} 

         else {
		circle(cx-x1,cy+y1,50);
		line(cx,cy,cx-x1,cy+y1);
	}

	delay(1);
	if(kbhit())
	        exit(0);
	return(0);
}

int main() {
	int gd=DETECT,gm=DETECT;
	initgraph(&gd,&gm,"");
	cleardevice();
	putpixel(200,100,4);

	while(1) {
		x=0;
		y=r;
		p=1-r;
		path(1);
		x=0;
		y=r;
		p=1-r;
		path(0);
	}
}
