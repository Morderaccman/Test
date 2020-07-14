#pragma once

#include "Items.h"

class IronMaterial;
class CopperMaterial;
class BoltMaterial;
class Box;

class Warehouse
{
public:
	Box* arrayBoxes;
	int m_amountofBox;
public:
	Warehouse(unsigned int amountofbox);
	~Warehouse();
private:
	
public:
	void FillBox();
	void TypeIndiacator(Iron item);
	void TypeIndiacator(Copper item);
	void TypeIndiacator(Bolt item);
	
};
class Box
{
public:
	Box(){}
	~Box(){}
	bool doesgetItem = false;
	TypeMaterials mTypeIronMaterial;
	int capacity;
	std::string strcapacity;
	std::string Name;
	std::string Description;
	std::string Icon;
};
class IronMaterial : public Iron
{
	
	
};
class CopperMaterial : public Copper
{
	TypeMaterials mTypeCopperMaterial = typeCopper;
};
class BoltMterial : public Bolt
{
	TypeMaterials mTypeCopperMaterial = typeCopper;
	TypeMaterials mTypeBoltMaterial = typeBolt;
};