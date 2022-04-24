template <typename T1, typename T2>
class Pair
{
public:
    Pair(T1 firstValue, T2 secondValue)
    {
        this->firstValue = firstValue;
        this->secondValue = secondValue;
    }

    T1 GetFirstValue()
    {
        return this->firstValue;
    }

    T2 GetSecondValue()
    {
        return this->secondValue;
    }

private:
    T1 firstValue;
    T2 secondValue;
};