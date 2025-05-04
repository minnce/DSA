#pragma once

namespace mystd
{
template <typename T1, typename T2> class pair
{
  public:
    T1 first;
    T2 second;

    pair(const T1 &f, const T2 &s) : first(f), second(s) {}

    pair() = default;

    bool operator==(const pair<T1, T2> &other) const
    {
        if (first == other.first && second == other.second)
        {
            return true;
        }
        return false;
    }
};

template <typename T1, typename T2> pair<T1, T2> make_pair(const T1 &f, const T2 &s) { return pair(f, s); }
} // namespace mystd