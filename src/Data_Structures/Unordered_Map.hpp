#pragma once
#include <Data_Structures/Pair.hpp>
#include <Data_Structures/Vector.hpp>

namespace mystd
{
template <typename T1, typename T2> class unordered_map
{
  public:
    unordered_map() = default;

    const T2& operator[] (const T1& k) const {

    }

    T2& operator[] (const T1 &k) {

    }
  private:
    size_t hash(const T1 &k) {
        return 0;
    }

    struct Bucket
    {
        vector<pair<T1, T2>> bucket;
    };

    size_t currSize;
    T1 key;
    vector<Bucket> value;
};
} // namespace mystd