#pragma once

#include "Renderer/Material.h"

/*
 * W pliku .obj znajduje się informacja o pliku, w którym zdefiniowane są materiały
 * (name) /\
 * 
 * Materiał posiada nazwę zdefiniowaną w pliku .mtl, która jest przypisywana do mesha w pliku .obj
 * (material.name) /\
 * 
 * Materiał posiada swoją definicję w pliku .mtl
 * (material) /\
 * 
 * Po wczytaniu pliku .obj mamy informację o pliku mtllib oraz przypisanie (po nazwie) materiału do mesha
 * 
 * Po wczytaniu pliku .mtl mamy definicje materiałów + nazwa pliku .mtl odpowiada mtllib w pliku .obj
 * 
 * Pliki wczytywane są oddzielnie
 * 
 * Po wczytaniu pliku .mtl dostajemy struct MaterialLibrary z informacją o nazwie oraz definicjami materiałów
 * 
 * Po wczytaniu pliku .obj dostajemy informację o bibliotece, a meshe mają przypisane materiały
 * 
 * Jeśli najpierw wczytamy plik .mtl, mamy MaterialLibrary, który po wczytaniu pliku .obj można znaleźć po nazwie i przypisać zdefinowane materiały meshom
 * 
 * Jeśli najpierw wczytamy plik .obj mamy nazwę MaterialLibrary. Po wczytaniu pliku .mtl można sprawdzić, czy obiekt korzysta z biblioteki i przypisać definicje materiałom
 */

struct MaterialLibrary
{
    std::string name;
    std::vector<std::shared_ptr<Material>> materials;
};