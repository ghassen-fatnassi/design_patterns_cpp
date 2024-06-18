#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    std::ios_base::sync_with_stdio(false);

const int MOD = 1e9 + 7;

// Inspired by Demon Slayer anime

class hashira // Abstract class (Product)
{
public:
    virtual void ultimateSkill() const = 0;
    virtual void swordSkill() const = 0;
    virtual void retreat() const = 0;
};

class flameHashira : public hashira // Concrete Product 1
{
public:
    void ultimateSkill() const override
    {
        cout << "Ninth Form: RENGOKU!\n";
    }
    void swordSkill() const override
    {
        cout << "First Form: Flame Pillar\n";
    }
    void retreat() const override
    {
        cout << "Flame Hashira gotta call for help\n";
    }
};

class waterHashira : public hashira // Concrete Product 2
{
public:
    void ultimateSkill() const override
    {
        cout << "Eleventh Form: DEAD CALM!\n";
    }
    void swordSkill() const override
    {
        cout << "First Form: Water Surface Slash!\n";
    }
    void retreat() const override
    {
        cout << "Water Hashira gotta call for help!\n";
    }
};

class demonSlayerCorp // Abstract Factory (Creator)
{
public:
    virtual hashira *summonHashira() const = 0; // Abstract factory method returning a pointer

    void fight(hashira *h) const
    {
        h->ultimateSkill();
        h->swordSkill();
        delete h; // Clean up dynamically allocated memory
    }
};

class flameCorp : public demonSlayerCorp // Concrete Factory 1
{
public:
    hashira *summonHashira() const override
    {
        cout << "Summoning Flame Hashira\n";
        return new flameHashira;
    }
};

class waterCorp : public demonSlayerCorp // Concrete Factory 2
{
public:
    hashira *summonHashira() const override
    {
        cout << "Summoning Water Hashira\n";
        return new waterHashira;
    }
};

int main()
{
    FASTIO;

    demonSlayerCorp *corp1 = new flameCorp();
    demonSlayerCorp *corp2 = new waterCorp();

    cout << "\nFlame Corp Fight:\n";
    hashira *h1 = corp1->summonHashira();
    corp1->fight(h1);

    cout << "\nWater Corp Fight:\n";
    hashira *h2 = corp2->summonHashira();
    corp2->fight(h2);

    delete corp1;
    delete corp2;

    return 0;
}
