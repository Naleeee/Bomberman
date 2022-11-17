/*
** EPITECH PROJECT, 2022
** Indie-Studio
** File description:
** Vector
*/

#include "Vector.hpp"

indie::Vector indie::Vector::operator+(indie::Vector other) const noexcept
{
    return {this->x + other.x, this->y + other.y, this->z + other.z};
}

indie::Vector indie::Vector::operator+(float other) const noexcept
{
    return {this->x + other, this->y + other, this->z + other};
}

indie::Vector indie::Vector::operator-(indie::Vector other) const noexcept
{
    return {this->x - other.x, this->y - other.y, this->z - other.z};
}

indie::Vector indie::Vector::operator-(float other) const noexcept
{
    return {this->x - other, this->y - other, this->z - other};
}

indie::Vector indie::Vector::operator*(indie::Vector other) const noexcept
{
    return {this->x * other.x, this->y * other.y, this->z * other.z};
}

indie::Vector indie::Vector::operator*(float other) const noexcept
{
    return {this->x * other, this->y * other, this->z * other};
}

indie::Vector indie::Vector::operator/(indie::Vector other) const noexcept
{
    if (other.x == 0 or other.y == 0 or other.z == 0) {
        return *this;
    }
    return {this->x / other.x, this->y / other.y, this->z / other.z};
}

indie::Vector indie::Vector::operator/(float other) const noexcept
{
    if (other == 0) {
        return *this;
    }
    return {this->x / other, this->y / other, this->z / other};
}

indie::Vector& indie::Vector::operator++() noexcept
{
    this->x++;
    this->y++;
    this->z++;

    return *this;
}

indie::Vector& indie::Vector::operator--() noexcept
{
    this->x--;
    this->y--;
    this->z--;

    return *this;
}

bool indie::Vector::operator==(const Vector& other) const noexcept
{
    return (this->x == other.x and this->y == other.y and this->z == other.z);
}

bool indie::Vector::operator!=(indie::Vector const& other) const noexcept
{
    return (this->x != other.x or this->y != other.y or this->z != other.z);
}

bool indie::Vector::operator>(indie::Vector const& other) const noexcept
{
    return (this->x > other.x and this->y > other.y and this->z > other.z);
}

bool indie::Vector::operator<(indie::Vector const& other) const noexcept
{
    return (this->x < other.x and this->y < other.y and this->z < other.z);
}

bool indie::Vector::operator>=(indie::Vector const& other) const noexcept
{
    return (this->x >= other.x and this->y >= other.y and this->z >= other.z);
}

bool indie::Vector::operator<=(indie::Vector const& other) const noexcept
{
    return (this->x <= other.x and this->y <= other.y and this->z <= other.z);
}

bool indie::Vector::operator!() const noexcept
{
    return (this->x == 0 and this->y == 0 and this->z == 0);
}

indie::Vector& indie::Vector::operator+=(indie::Vector other) noexcept
{
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;

    return *this;
}

indie::Vector& indie::Vector::operator-=(indie::Vector other) noexcept
{
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;

    return *this;
}

indie::Vector& indie::Vector::operator*=(indie::Vector other) noexcept
{
    this->x *= other.x;
    this->y *= other.y;
    this->z *= other.z;

    return *this;
}

indie::Vector& indie::Vector::operator/=(Vector other) noexcept
{
    if (other.x == 0 or other.y == 0 or other.z == 0) {
        return *this;
    }
    this->x /= other.x;
    this->y /= other.y;
    this->z /= other.z;

    return *this;
}

indie::Vector::operator Vector3() const
{
    return {this->x, this->y, this->z};
}

std::size_t indie::VectorHash::operator()(const Vector& vector) const noexcept
{
    std::size_t h1 = std::hash<float>()(vector.x);
    std::size_t h2 = std::hash<float>()(vector.y);
    std::size_t h3 = std::hash<float>()(vector.z);

    return (h1 ^ h2 ^ h3);
}
