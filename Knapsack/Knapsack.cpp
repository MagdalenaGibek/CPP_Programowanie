#include "Knapsack.hpp"
#include <random>

Item Shop::steal(int index)
{
    Item result;
    result.value = items[index].value;
    result.weight = items[index].weight;
    items[index].value = 0;
    items[index].weight = 0;
    return result;
}

Item Shop::peek(int index)
{
    Item result;
    result.value = items[index].value;
    result.weight = items[index].weight;
    return result;
}

int Backpack::put(Item item)
{
    stolen[firstAvailableIndex].value = item.value;
    stolen[firstAvailableIndex].weight = item.weight;
    firstAvailableIndex++;
    currentCapacity += item.weight;
    return capacity - currentCapacity;
}

Item* Shop::getItems() const
{
    return (Item*)items;
}

int Robber::getValue()
{
    return backpack.calculateCurrentValue();
}

Item* Robber::getBackpackItems() const
{
    return backpack.getItems();
}

void Robber::robWhatever(Shop& shop)
{
    for (int i = 0; i < 10; i++)
    {
        Item item = shop.peek(i);
        if (backpack.fits(item.weight))
        {
            Item item = shop.steal(i);
            backpack.put(item);
        }
    }
}

void Robber::robGreedy(Shop& shop)
{
    double* factors = new double[10];
    initFactor(shop, factors);
    for (int i = 0; i < 10; i++)
    {
        int maxIndex = -1;
        double maxFactor = -1;
        for (int j = 0; j < 10; j++)
        {
            if (factors[j] > maxFactor)
            {
                maxFactor = factors[j];
                maxIndex = j;
            }
        }
        factors[maxIndex] = 0.0;

        // czy zmieści się w plecaku
        Item item = shop.peek(maxIndex);
        if (maxFactor == 0.0 || !backpack.fits(item.weight))
        {
            continue;
        }
        
        backpack.put(shop.steal(maxIndex));

        delete[] factors;
    }
}

void Robber::initFactor(Shop& shop, double* factors)
{

    for (int i = 1; i < 10; i++)
    {
        Item item = shop.peek(i);
        double efficientFactor = item.value / item.weight;
        factors[i] = efficientFactor;
    }
}




Shop::Shop()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 15);

    for (int i = 0; i < 10; i++)
    {
        items[i].weight = distr(gen);
        items[i].value = distr(gen);
    }
}

Robber::Robber(int capacity) : backpack(capacity) { }

Backpack::Backpack(int _capacity) : capacity(_capacity)
{
    for (int i = 0; i < 10; i++)
    {
        stolen[i].value = 0;
        stolen[i].weight = 0;
    }
}

Item* Backpack::getItems() const
{
    return (Item*)stolen;
}

bool Backpack::fits(int weight)
{
    //czy obiekt zmiesci do naszego plecaka
    return currentCapacity + weight <= capacity;
}

int Backpack::calculateCurrentValue() const
{
    int result = 0;
    for (int i = 0; i < firstAvailableIndex; ++i)
    {
        result += stolen[i].value;
    }

    return result;
}

std::ostream& operator<<(std::ostream& s, const Shop& shop)
{
    Item* items = shop.getItems();
    s << "Shop: " << std::endl;
    for (int i = 0; i < 10; i++)
    {
        s << items[i].value << " " << items[i].weight << std::endl;;
    }
    s << "End of shop: " << std::endl;
    return s;
}

//int&           add      (int           a, const int       b)  // analogiczna struktura
std::ostream& operator<<(std::ostream& s, const Robber& r)
{
    Item* items = r.getBackpackItems();
    s << "Backpack: " << std::endl;
    for (int i = 0; i < 10; i++)
    {
        s << items[i].value << " " << items[i].weight << std::endl;
    }
    s << "End of backpack: " << std::endl;
    return s;
}

