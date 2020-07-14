#pragma once
#include "i4pch.h"
#include <d3d9.h>
#include "d3dx9.h"


#define DRIB(x) (1 << x)
enum TypeMaterials
{
	typeIron = DRIB(0),
	typeCopper = DRIB(1),
	typeBolt = DRIB(2)
};
//D3DXCreateTextureFromFile(g_pd3dDevice, L"morderaccmanFace.png", &ppTexture);
//LPDIRECT3DTEXTURE9 ppTexture
class Items
{
public:
	Items(){}
	~Items(){}
	virtual TypeMaterials getTypeMaterial() = 0;
	virtual int getCapacity() = 0;
	virtual std::string getstrCapacity() = 0;
	virtual std::string getName() = 0;
	virtual std::string getDescription() = 0;
	virtual std::string getIcon() = 0;

};

class Iron : public Items
{
public:
	Iron() {}
	~Iron() {}
	virtual TypeMaterials getTypeMaterial() { return typeIron; }
	virtual int getCapacity() override { return 64; }
	virtual std::string getstrCapacity() override { return "64"; }
	virtual std::string getName() override { return "Iron"; }
	virtual std::string getDescription() override { return "Description to Iron"; }
	virtual std::string getIcon() override { return "Icons/Iron.png"; }
};

class Copper : public Items
{
public:
	virtual TypeMaterials getTypeMaterial() { return typeCopper; }
	virtual int getCapacity() override { return 54; }
	virtual std::string getstrCapacity() override { return "54"; }
	virtual std::string getName() override { return "Copper"; }
	virtual std::string getDescription() override { return "Description to Copper"; }
	virtual std::string getIcon() override { return "Icons/Copper.png"; }
};

class Bolt : public Items
{
public:
	virtual TypeMaterials getTypeMaterial() { return typeBolt; }
	virtual int getCapacity() override { return 76; }
	virtual std::string getstrCapacity() override { return "76"; }
	virtual std::string getName() override { return "Bolt"; }
	virtual std::string getDescription() override { return "Description to Bolt"; }
	virtual std::string getIcon() override { return "Icons/Bolt.png"; }
};
