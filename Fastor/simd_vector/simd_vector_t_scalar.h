#ifndef SIMD_VECTOR_T_SCALAR_H
#define SIMD_VECTOR_T_SCALAR_H

#include "simd_vector_base.h"

namespace Fastor {

template <typename T>
struct SIMDVector<T, simd_abi::scalar> {
    using value_type = T;
    using scalar_value_type = T;
    using abi_type = simd_abi::scalar;
    static constexpr FASTOR_INDEX Size = 1;
    static constexpr FASTOR_INLINE FASTOR_INDEX size() {return 1;}
    static constexpr int unroll_size(FASTOR_INDEX size) {return (static_cast<int>(size) - 1);}

    FASTOR_INLINE SIMDVector() : value(0) {}
    FASTOR_INLINE SIMDVector(T num) : value(num) {}
    FASTOR_INLINE SIMDVector(const SIMDVector<T,simd_abi::scalar> &a) : value(a.value) {}
    FASTOR_INLINE SIMDVector(const T *data, bool Aligned=true) : value(*data) {}
    FASTOR_INLINE SIMDVector(T *data, bool Aligned=true) : value(*data) {}

    FASTOR_INLINE SIMDVector<T,simd_abi::scalar> operator=(T num) {
        value = num;
        return *this;
    }
    FASTOR_INLINE SIMDVector<T,simd_abi::scalar> operator=(const SIMDVector<T,simd_abi::scalar> &a) {
        value = a.value;
        return *this;
    }

    FASTOR_INLINE void load(const T *data, bool ) {
        value = *data;
    }
    FASTOR_INLINE void store(T *data, bool ) const {
        data[0] = value;
    }

    FASTOR_INLINE void load(const T *data) {
        value = *data;
    }
    FASTOR_INLINE void store(T *data) const {
        data[0] = value;
    }

    FASTOR_INLINE void aligned_load(const T *data) {
        value = *data;
    }
    FASTOR_INLINE void aligned_store(T *data) const {
        data[0] = value;
    }

    FASTOR_INLINE T operator[](FASTOR_INDEX) const {return value;}
    FASTOR_INLINE T operator()(FASTOR_INDEX) const {return value;}

    FASTOR_INLINE void set(T num) {
        value = num;
    }

    FASTOR_INLINE void set_sequential(T num) {
        value = num;
    }

    FASTOR_INLINE void broadcast(const T *data) {
        value = *data;
    }

    // In-place operators
    FASTOR_INLINE void operator+=(T num) {
        value += num;
    }
    FASTOR_INLINE void operator+=(const SIMDVector<T,simd_abi::scalar> &a) {
        value += a.value;
    }

    FASTOR_INLINE void operator-=(T num) {
        value -= num;
    }
    FASTOR_INLINE void operator-=(const SIMDVector<T,simd_abi::scalar> &a) {
        value -= a.value;
    }

    FASTOR_INLINE void operator*=(T num) {
        value *= num;
    }
    FASTOR_INLINE void operator*=(const SIMDVector<T,simd_abi::scalar> &a) {
        value *= a.value;
    }

    FASTOR_INLINE void operator/=(T num) {
        value /= num;
    }
    FASTOR_INLINE void operator/=(const SIMDVector<T,simd_abi::scalar> &a) {
        value /= a.value;
    }
    // end of in-place operators

    FASTOR_INLINE SIMDVector<T,simd_abi::scalar> shift(FASTOR_INDEX) {
        return *this;
    }
    FASTOR_INLINE T sum() {return value;}
    FASTOR_INLINE T product() {return value;}
    FASTOR_INLINE SIMDVector<T,simd_abi::scalar> reverse() {
        return *this;
    }
    FASTOR_INLINE T minimum() {return value;}
    FASTOR_INLINE T maximum() {return value;}

    FASTOR_INLINE T dot(const SIMDVector<T,simd_abi::scalar> &other) {
        return value*other.value;
    }

    T value;
};

template <typename T>
FASTOR_HINT_INLINE std::ostream& operator<<(std::ostream &os, SIMDVector<T,simd_abi::scalar> a) {
    os << "[" << a.value << "]\n";
    return os;
}

template <typename T>
FASTOR_INLINE SIMDVector<T,simd_abi::scalar> operator+(const SIMDVector<T,simd_abi::scalar> &a, const SIMDVector<T,simd_abi::scalar> &b) {
    SIMDVector<T,simd_abi::scalar> out;
    out.value = a.value+b.value;
    return out;
}
template <typename T>
FASTOR_INLINE SIMDVector<T,simd_abi::scalar> operator+(const SIMDVector<T,simd_abi::scalar> &a, T b) {
    SIMDVector<T,simd_abi::scalar> out;
    out.value = a.value+b;
    return out;
}
template <typename T>
FASTOR_INLINE SIMDVector<T,simd_abi::scalar> operator+(T a, const SIMDVector<T,simd_abi::scalar> &b) {
    SIMDVector<T,simd_abi::scalar> out;
    out.value = a+b.value;
    return out;
}
template <typename T>
FASTOR_INLINE SIMDVector<T,simd_abi::scalar> operator+(const SIMDVector<T,simd_abi::scalar> &b) {
    return b;
}

template <typename T>
FASTOR_INLINE SIMDVector<T,simd_abi::scalar> operator-(const SIMDVector<T,simd_abi::scalar> &a, const SIMDVector<T,simd_abi::scalar> &b) {
    SIMDVector<T,simd_abi::scalar> out;
    out.value = a.value-b.value;
    return out;
}
template <typename T>
FASTOR_INLINE SIMDVector<T,simd_abi::scalar> operator-(const SIMDVector<T,simd_abi::scalar> &a, T b) {
    SIMDVector<T,simd_abi::scalar> out;
    out.value = a.value-b;
    return out;
}
template <typename T>
FASTOR_INLINE SIMDVector<T,simd_abi::scalar> operator-(T a, const SIMDVector<T,simd_abi::scalar> &b) {
    SIMDVector<T,simd_abi::scalar> out;
    out.value = a-b.value;
    return out;
}
template <typename T>
FASTOR_INLINE SIMDVector<T,simd_abi::scalar> operator-(const SIMDVector<T,simd_abi::scalar> &b) {
    SIMDVector<T,simd_abi::scalar> out;
    out.value = -b.value;
    return out;
}

template <typename T>
FASTOR_INLINE SIMDVector<T,simd_abi::scalar> operator*(const SIMDVector<T,simd_abi::scalar> &a, const SIMDVector<T,simd_abi::scalar> &b) {
    SIMDVector<T,simd_abi::scalar> out;
    out.value = a.value*b.value;
    return out;
}
template <typename T>
FASTOR_INLINE SIMDVector<T,simd_abi::scalar> operator*(const SIMDVector<T,simd_abi::scalar> &a, T b) {
    SIMDVector<T,simd_abi::scalar> out;
    out.value = a.value*b;
    return out;
}
template <typename T>
FASTOR_INLINE SIMDVector<T,simd_abi::scalar> operator*(T a, const SIMDVector<T,simd_abi::scalar> &b) {
    SIMDVector<T,simd_abi::scalar> out;
    out.value = a*b.value;
    return out;
}

template <typename T>
FASTOR_INLINE SIMDVector<T,simd_abi::scalar> operator/(const SIMDVector<T,simd_abi::scalar> &a, const SIMDVector<T,simd_abi::scalar> &b) {
    SIMDVector<T,simd_abi::scalar> out;
    out.value = a.value/b.value;
    return out;
}
template <typename T>
FASTOR_INLINE SIMDVector<T,simd_abi::scalar> operator/(const SIMDVector<T,simd_abi::scalar> &a, T b) {
    SIMDVector<T,simd_abi::scalar> out;
    out.value = a.value/b;
    return out;
}
template <typename T>
FASTOR_INLINE SIMDVector<T,simd_abi::scalar> operator/(T a, const SIMDVector<T,simd_abi::scalar> &b) {
    SIMDVector<T,simd_abi::scalar> out;
    out.value = a/b.value;
    return out;
}

template <typename T>
FASTOR_INLINE SIMDVector<T,simd_abi::scalar> rcp(const SIMDVector<T,simd_abi::scalar> &a) {
    return 1 / a.value;
}

template <typename T>
FASTOR_INLINE SIMDVector<T,simd_abi::scalar> sqrt(const SIMDVector<T,simd_abi::scalar> &a) {
    return std::sqrt(a.value);
}

template <typename T>
FASTOR_INLINE SIMDVector<T,simd_abi::scalar> rsqrt(const SIMDVector<T,simd_abi::scalar> &a) {
    return 1/std::sqrt(a.value);
}

template <typename T>
FASTOR_INLINE SIMDVector<T,simd_abi::scalar> abs(const SIMDVector<T,simd_abi::scalar> &a) {
    return std::abs(a.value);
}

} // end of namespace Fastor


#endif // SIMD_VECTOR_T_SCALAR_H