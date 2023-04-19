#include <iostream>
#include <cmath>
using namespace std;

double intersecao(double qx,double qy,double ql,double cx,double cy,double cr){
    double area = 0;
    //quadrado está garantidamente fora do circulo e vice-versa se o ponto do circulo mais proximo do quadrado for maior ou menor dependendo se esta em cima abaixo à esqerda à direita do quadrado
    if ((cx - cr > qx + ql) || (cy - cr > qy + ql) || (cx + cr < qx) || (cy + cr < qy)){
        return 0;
    }
    //verificar se o circulo esta dentro do quadrado
    else if ((cx + cr <= qx + ql) && (cy + cr <= qy + ql) && (cx - cr >= qx) && (cy - cr >= qy)){
        return M_PI * cr * cr; //retornar área do quadrado
    }
    // Verifica se o quadrado está dentro do círculo, 
    // todos os vertices do quadrado estao dentro do circulo


    else if ((sqrt((cx - qx) * (cx - qx) + (cy - qy) * (cy - qy)) <= cr) && (sqrt((qx + ql - cx) * (qx + ql - cx) + (cy - qy) * (cy - qy)) <= cr) && (sqrt((qx + ql - cx) * (qx + ql - cx) + (qy + ql - cy) * (qy + ql - cy)) <= cr) && (sqrt((cx - qx) * (cx - qx) + (qy + ql - cy) * (qy + ql - cy)) <= cr)){
        return ql * ql;
    }
    else if (ql >= 0.001){
        ql /= 2;
        area += intersecao(qx,qy + ql,ql,cx,cy,cr);
        area += intersecao(qx + ql,qy + ql,ql,cx,cy,cr);
        area += intersecao(qx,qy,ql,cx,cy,cr);
        area += intersecao(qx + ql,qy,ql,cx,cy,cr);
    }
    return area;
}

int main(){
    double N,qx,qy,ql,cx,cy,cr;
    cin >> N;
    for (int i=0;i<N;i++){
        cin >> qx >> qy >> ql >> cx >> cy >> cr;
        cout << intersecao(qx,qy,ql,cx,cy,cr) << endl;
    }
    return 0;
}