#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include "CharCreation.h"
#include "Character.h"
#include "Troll.h"

void Battle(Character &player, CharCreation ** monster, int battleCount);
void PlayersTurn(Character& player, CharCreation** monster, int battleCount);
void PlayerHit(int damage, int enemyArmor, CharCreation** monster, int battleCount);
void MonstersTurn(Character& player, CharCreation** monster, int battleCount, int maxHealth, int maxArmor);
void MonsterHit(int damage, int enemyArmor, Character& player, int battleCount);

int main()
{	
	CharCreation* Enemies[10];
	Enemies[0] = new Troll;
	Character newChar;
	String name;
	int choice = 0;
	int reroll = 0;
	int battleCount = 0;
	cout << "1.) Create a New Character" << endl;
	cout << "2.) Resume a Character" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cin.ignore();
		cout << "Enter a Character Name" << endl;
		cin >> name;
		newChar.SetName(name);
		newChar.Display();

		while (reroll != 2)
		{
			cout << "1.) Re-roll stats of Character" << endl;
			cout << "2.) Finish Character Creation" << endl;
			cin >> reroll;                      
			switch (reroll)
			{
			case 1:
				newChar.Rroll();
				newChar.DisplayAttributes();
				break;
			case 2:
				cout << "1.) Battle in the Arena" << endl;
				//cout << "2.) Visit the Potions Shop" << endl;
				//cout << "3.) Visit the Blacksmith" << endl;
				//cout << "4.) Save Character and exit game" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
					Battle(newChar, Enemies, battleCount);
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				}
				break;
			default:
				cout << "Please choose a valid option" << endl;
			}
		}
	case 2:
	default:
		cout << "Please choose a valid option" << endl;
	}

	return 0;
}

void Battle(Character &player, CharCreation ** monster, int battleCount)
{
	int maxHealth = monster[battleCount]->GetHitPoints();
	int maxArmor = monster[battleCount]->GetArmor();
	cout << "You enter the arena to see a ";
	monster[battleCount]->WhatAmI();
	cout << "Battle Begin!" << endl;
	while ((player.GetHitPoints() > 0) && (monster[battleCount]->GetHitPoints() > 0))
	{
		PlayersTurn(player, monster, battleCount);
		MonstersTurn(player, monster, battleCount, maxHealth, maxArmor);
	}
	if (player.GetHitPoints() > 0)
	{
		cout << "Victory!" << endl;
	}
	else
	{
		cout << "Defeat!" << endl;
	}
	battleCount++;
}

void PlayersTurn(Character& player, CharCreation ** monster, int battleCount)
{
	int choice = 0;
	int hit = 0;
	int damage = player.GetDamage();
	int armor = player.GetArmor();
	int health = player.GetHitPoints();
	int enemyDamage = monster[battleCount]->GetDamage();
	int enemyArmor = monster[battleCount]->GetArmor();
	int enemyHP = monster[battleCount]->GetHitPoints();
	cout << "1.) Basic Attack" << endl;
	cout << "2.) Block" << endl;
	cout << "3.) Berserk" << endl;
	cout << "4.) Special" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		hit = (int)(1 + rand() % 20);
		if (hit == 20)
		{
			damage = damage * 2;
			cout << "You Critically Strike ";
			monster[battleCount]->WhatAmI();
			cout << " for " << damage << " damage" << endl;
			PlayerHit(damage, enemyArmor, monster, battleCount);
			monster[battleCount]->Display();
		}
		else if (hit >= 5)
		{
			damage = player.GetDamage();
			cout << "You hit ";
			monster[battleCount]->WhatAmI();
			cout << " for " << damage << " damage" << endl;
			PlayerHit(damage, enemyArmor, monster, battleCount);
			monster[battleCount]->Display();
		}
		else
		{
			cout << "You miss the ";
			monster[battleCount]->WhatAmI();
			monster[battleCount]->Display();
		}
		break;
	case 2:
		player.SetArmor(player.GetArmor() + 3);
		break;
	case 3:
		player.SetDamage(player.GetDamage() + 1);
		player.SetArmor(player.GetArmor() - 1);

		break;
	case 4:
		player.Special();
		break;
	default:
		cout << "Please choose a valid option" << endl;
	}
}

void PlayerHit(int damage, int enemyArmor, CharCreation** monster, int battleCount)
{
	if (enemyArmor == 0)
	{
		monster[battleCount]->SetHitPoints(monster[battleCount]->GetHitPoints() - damage);
	}
	else if (enemyArmor < damage)
	{
		damage = damage - enemyArmor;
		monster[battleCount]->SetArmor(0);
		monster[battleCount]->SetHitPoints(monster[battleCount]->GetHitPoints() - damage);
	}
	else
	{
		monster[0]->SetArmor(monster[battleCount]->GetArmor() - damage);
	}
}

void MonstersTurn(Character& player, CharCreation** monster, int battleCount, int maxHealth, int maxArmor)
{
	int choice = 0;
	int hit = 0;
	int damage = monster[battleCount]->GetDamage();
	int armor = monster[battleCount]->GetArmor();
	int health = monster[battleCount]->GetHitPoints();
	int enemyDamage = player.GetDamage();
	int enemyArmor = player.GetArmor();
	int enemyHP = player.GetHitPoints();

	if (health < maxHealth - 3)
	{
		choice = 4;
	}
	else if (armor == 0)
	{
		choice = 2;
	}
	else if (armor == maxArmor && health == maxHealth)
	{
		choice = 3;
	}
	else
	{
		choice = 1;
	}
	switch (choice)
	{
	case 1:
		hit = (int)(1 + rand() % 20);
		if (hit == 20)
		{
			damage = damage * 2;
			cout << "You are Critically Hit by a ";
			monster[battleCount]->WhatAmI();
			cout << " for " << damage << " damage" << endl;
			MonsterHit(damage, enemyArmor, player, battleCount);
			player.Display();
		}
		else if (hit >= 10)
		{
			damage = player.GetDamage();
			cout << "You are hit by a ";
			monster[battleCount]->WhatAmI();
			cout << " for " << damage << " damage" << endl;
			MonsterHit(damage, enemyArmor, player, battleCount);
			player.Display();
		}
		else
		{
			monster[battleCount]->WhatAmI();
			cout << "Misses you";
			player.DisplayAttributes();
		}
		break;
	case 2:
		cout << "The ";
		monster[battleCount]->WhatAmI();
		cout << " blocks";
		monster[battleCount]->SetArmor(monster[battleCount]->GetArmor() + 3);
		monster[battleCount]->Display();
		break;
	case 3:
		monster[battleCount]->SetDamage(monster[battleCount]->GetDamage() + 1);
		monster[battleCount]->SetArmor(monster[battleCount]->GetArmor() - 1);
		break;
	case 4:
		monster[battleCount]->Special();
		break;
	}
}

void MonsterHit(int damage, int enemyArmor, Character& player, int battleCount)
{
	if (enemyArmor == 0)
	{
		player.SetHitPoints(player.GetHitPoints() - damage);
	}
	else if (enemyArmor < damage)
	{
		damage = damage - enemyArmor;
		player.SetArmor(0);
		player.SetHitPoints(player.GetHitPoints() - damage);
	}
	else
	{
		player.SetArmor(player.GetArmor() - damage);
	}
}