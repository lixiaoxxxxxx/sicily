#include <iostream>
#include <math.h>
using namespace std;
struct loc{
	double x1;
	double y1;
	double x2;
	double y2;
	double angle;
	double y;
};

int judge(loc &a, double y1, double y2, double x1, double x2){
	double miny, maxy, minay, maxay;
	double new_x1, new_x2, new_y1, new_y2;
	new_x1 = min(min(x1, x2), min(a.x1, a.x2));
	new_y1 = min(min(y1, y2), min(a.y1, a.y2));
	new_x2 = max(max(x1, x2), max(a.x1, a.x2));
	new_y2 = max(max(y1, y2), max(a.y1, a.y2));
	if (min(x1, x2) > max(a.x1, a.x2) || max(x1, x2) < min(a.x1, a.x2) || min(y1, y2) > max(a.y1, a.y2) || max(y1, y2) < min(a.y1, a.y2)){
		return 0;
	}
	else{
		a.x1 = new_x1;
		a.x2 = new_x2;
		a.y1 = new_y1;
		a.y2 = new_y2;
		return 1;
	}
}

int main (){
	int k;
	double x1, y1, x2, y2;
	loc locx[10000];
	loc locy[10000];
	double angle;
	double x;
	double y;
	int cx = 0;
	int cy = 0;
	int ans = 0;
	cin >> k;
	while (k != 0){
		for (int j = 0; j < k; j++){
			cin >> x1 >> y1 >> x2 >> y2;
			if (fabs(x1 - x2) < 0.00000001){
				if (cx == 0){
					locx[cx].x1 = x1;
					locx[cx].y1 = y1;
					locx[cx].x2 = x2;
					locx[cx].y2 = y2;
					ans++;
					cx++;
				}
				else{
					int flag = 0;
					for (int i = 0; i < cx; i++){
						if (fabs(x1 - locx[i].x1) < 0.00000001){
							flag = 1;
							if (judge (locx[i], y1, y2, x1, x2)){
								break;
							}
						}
					}
					if (flag == 0){
						locx[cx].x1 = x1;
						locx[cx].y1 = y1;
						locx[cx].x2 = x2;
						locx[cx].y2 = y2;
						ans++;
						cx++;
					}
				}
			}
			else{
				angle = (y1 - y2) / (x1 - x2);
				y = angle * (-x1) + y1;
				if (cy == 0){
					locy[cy].x1 = x1;
					locy[cy].y1 = y1;
					locy[cy].x2 = x2;
					locy[cy].y2 = y2;
					locy[cy].y = y;
					locy[cy].angle = angle;
					ans ++;
					cy++;
				}
				else{
					int flag = 0;
					for (int i = 0; i < cy; i++){
						if ((fabs(angle - locy[i].angle) < 0.00000001) && (fabs(y - locy[i].y) < 0.00000001)){
							flag = 1;
							if (judge (locy[i], y1, y2, x1, x2)){
								break;
							}
						}
					}
					if (flag == 0){
						locy[cy].x1 = x1;
						locy[cy].y1 = y1;
						locy[cy].x2 = x2;
						locy[cy].y2 = y2;
						locy[cy].y = y;
						locy[cy].angle = angle;
						ans ++;
						cy++;
					}
				}
			}
		}
		cout << ans << endl;
		cx = 0;
		ans = 0;
		cy = 0;
		cin >> k;
	}
	return 0;
}
