#pragma once
#include "Computer.h"

class computerList
{
private:
	computer** computers; // ������ �����������
	int count; // ���������� �������
	int capacity; // �����������
public:
	computerList(int n);
	~computerList();

	void readComputers(); // ������� ����������
	void showComputers(); // �������� ����������
	void addComputer(); //�������� ��
	void deleteComputer(); //������� ��
	void saveIntoFile(); //��������� � ����
	

	//�������: 
	void Price20To30();
	void TotalCost();
	void RedOrBlue();
	void SearchByType();
};