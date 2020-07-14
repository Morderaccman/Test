#include "i4pch.h"
#include "Warehouse.h"

Warehouse::Warehouse(unsigned int amountofbox)
{
	arrayBoxes = new Box[amountofbox];
	m_amountofBox = amountofbox;
}
Warehouse::~Warehouse()
{}
void Warehouse::TypeIndiacator(Iron item)
{
	for (int i = 0; i < m_amountofBox; i++)
	{
		if (arrayBoxes[i].doesgetItem != true)
		{
			arrayBoxes[i].capacity = item.getCapacity();
			arrayBoxes[i].strcapacity = item.getstrCapacity();
			arrayBoxes[i].Description = item.getDescription();
			arrayBoxes[i].mTypeIronMaterial = item.getTypeMaterial();
			arrayBoxes[i].Name = item.getName();
			arrayBoxes[i].Icon = item.getIcon();
			arrayBoxes[i].doesgetItem = true;
			break;
		}
	}
} 
void Warehouse::TypeIndiacator(Copper item)
{
	for (int i = 0; i < m_amountofBox; i++)
	{
		if (arrayBoxes[i].doesgetItem != true)
		{
			arrayBoxes[i].capacity = item.getCapacity();
			arrayBoxes[i].strcapacity = item.getstrCapacity();
			arrayBoxes[i].Description = item.getDescription();
			arrayBoxes[i].mTypeIronMaterial = item.getTypeMaterial();
			arrayBoxes[i].Name = item.getName();
			arrayBoxes[i].Icon = item.getIcon();
			arrayBoxes[i].doesgetItem = true;
			break;
		}
	}
}
void Warehouse::TypeIndiacator(Bolt item)
{
	for (int i = 0; i < m_amountofBox; i++)
	{
		if (arrayBoxes[i].doesgetItem != true)
		{
			arrayBoxes[i].capacity = item.getCapacity();
			arrayBoxes[i].strcapacity = item.getstrCapacity();
			arrayBoxes[i].Description = item.getDescription();
			arrayBoxes[i].mTypeIronMaterial = item.getTypeMaterial();
			arrayBoxes[i].Name = item.getName();
			arrayBoxes[i].Icon = item.getIcon();
			arrayBoxes[i].doesgetItem = true;
			break;
		}
	}
}
void Warehouse::FillBox()
{

}