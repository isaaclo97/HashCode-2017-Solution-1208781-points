#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main()
{
    int videos, endpoints, request_descriptions, caches,tamano;
    vector<int> video;
    vector<int> number;
    vector<string> lineas;
    FILE* fichero;
    fichero=fopen("C:/Users/Isaac/Desktop/HashCode/trending_today.in","r+");
    string linea,linea2,linea3,linea4;
    char caracter;
    caracter=fgetc(fichero);
    while(caracter!=EOF) //Almacenar directamente optimizacion
    {
        linea+=caracter;
        caracter=fgetc(fichero);
    }
    for(unsigned int i =0; i<linea.length();i++)
    {
        if(linea[i]!='\n')
            linea2+=linea[i];
        else
        {
            lineas.push_back(linea2);
            linea2="";
        }
    }
    linea3=lineas[0];
    for(unsigned int i=0;i<linea3.length();i++)
    {
        if(linea3[i]!=' ')
            linea4+=linea3[i];
        else
        {
            int numero = stoi(linea4);
            number.push_back(numero);
            linea4="";
        }
    }
    number.push_back(stoi(linea4));
    videos=number[0];
    endpoints=number[1];
    request_descriptions=number[2];
    caches=number[3];
    tamano=number[4];
    linea3=lineas[1];
    linea4="";
    for(unsigned int j=0; j<linea3.length();j++)
    {
        if(linea3[j]!=' ')
            linea4+=linea3[j];
        else
        {
            int numero = stoi(linea4);
            video.push_back(numero);
            linea4="";
        }
    }
    int numero=stoi(linea4);
    video.push_back(numero);
    linea4="";

    vector<int> reduccion;
    vector<int> vidsInCache[caches];
    int asignado =0;
    for (int i =0 ; i < caches ; i++ ){
        reduccion.push_back(tamano);
    }
    for (int i=0; i < videos;i++){
        asignado =0;
        for(int j = 0;j<caches && asignado==0;j++){
            if (reduccion[j]-video[i]>0){
                reduccion[j]=reduccion[j]-video[i];
                vidsInCache[j].push_back(i);
                asignado=1;
            }
        }
    }
    for (int i=0; i < videos;i++){
        asignado =0;
        for(int j = 0;j<caches && asignado==0;j++){
            if (reduccion[j]-video[i]>0){
                reduccion[j]=reduccion[j]-video[i];
                vidsInCache[j].push_back(i);
                asignado=1;
            }
        }
    }
    cout<<caches<<endl;
    string solucion_3;
    for (int i = 0;i< caches;i++){
        cout<<i<<" ";
        solucion_3+=to_string(i)+" ";
        for (int j=0;j<vidsInCache[i].size();j++){
            cout<<(vidsInCache[i])[j]<<" ";
            solucion_3+=to_string((vidsInCache[i])[j]);
            solucion_3+=" ";
        }
        cout<<endl;
        solucion_3+='\n';
    }

    FILE* soluction;
    soluction=fopen("C:/Users/Isaac/Desktop/HashCode/soluciones_11_1.in","w+");
    string soluciones;
    soluciones += to_string(caches);
    soluciones +="\n";
    soluciones+=solucion_3;
    fprintf(soluction,"%s",soluciones.c_str());
    return 0;
}
