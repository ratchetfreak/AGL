#pragma once

#include <math.h>
#include <ostream>
#include <sstream>

#define PI 3.14159

namespace agl
{
	template <typename T, int max> class Vec;
  
  template <typename T> class Vec<T, 2>
	{
    static const int max = 2;
		public:
			// \ Construct Vec with data starting all at 0
			Vec()
			{
			}

			// \ Construct Vec to be equal to vec
			// \ &vec - vec for data to be equal to
			Vec(Vec const &vec)
			{
				for (unsigned int i = 0; i < max; i++)
				{
					data[i] = vec.data[i];
				}
			}

			template <typename U, int amount> Vec(Vec<U, amount> const &vec)
			{
				unsigned int i;

				for (i = 0; (i < max) && (i < amount); i++)
				{
					data[i] = vec.data[i];
				}

				for (; i < max; i++)
				{
					data[i] = 0;
				}
			}

			// \ Construct Vec to xyzw values
			// \ x - X value
			// \ y - Y value
			// \ z - Z value
			// \ w - W value
			Vec(T x, T y, T z, T w)
			{
				this->x = x;
				this->y = y;
				this->z = z;
				this->w = w;
			}

			// \ Construct Vec to xyz values
			// \ x - X value
			// \ y - Y value
			// \ z - Z value
			Vec(T x, T y, T z)
			{
				this->x = x;
				this->y = y;
				this->z = z;
			}

			// \ Construct Vec to xy values
			// \ x - X value
			// \ y - Y value
			Vec(T x, T y)
			{
				this->x = x;
				this->y = y;
			}

			// \ Construct Vec to x value
			// \ x - X value
			Vec(T x)
			{
				this->x = x;
			}

			void operator=(Vec vec)
			{
				for (unsigned int i = 0; i < max; i++)
				{
					data[i] = vec.data[i];
				}
			}

			void operator+=(Vec vec)
			{
				for (unsigned int i = 0; i < max; i++)
				{
					data[i] += vec.data[i];
				}
			}

			void operator-=(Vec vec)
			{
				for (unsigned int i = 0; i < max; i++)
				{
					data[i] -= vec.data[i];
				}
			}

			void operator*=(T scale)
			{
				for (unsigned int i = 0; i < max; i++)
				{
					data[i] *= scale;
				}
			}

			void operator/=(T scale)
			{
				for (unsigned int i = 0; i < max; i++)
				{
					data[i] /= scale;
				}
			}

			Vec operator-(Vec vec)
			{
				Vec newVec;

				for (int i = 0; i < max; i++)
				{
					newVec.data[i] = data[i] - vec.data[i];
				}

				return newVec;
			}

			Vec operator+(Vec vec)
			{
				Vec newVec;

				for (int i = 0; i < max; i++)
				{
					newVec.data[i] = data[i] + vec.data[i];
				}

				return newVec;
			}

			Vec operator*(T scale)
			{
				Vec newVec;

				for (int i = 0; i < max; i++)
				{
					newVec.data[i] = data[i] * scale;
				}

				return newVec;
			}

			Vec operator/(T scale)
			{
				Vec newVec;

				for (int i = 0; i < max; i++)
				{
					newVec.data[i] = data[i] / scale;
				}

				return newVec;
			}

			// \ Get length of Vec
			T length()
			{
				return sqrt(this->dot(*this));
			}

			// \ Normalize Vec
			Vec normalized()
			{
				T len = this->length();
				return {x / len, y / len};
			}

			// \ Get the dot product of Vec and vec
			// \ vec - second vector
			float dot(Vec vec)
			{
				float dot = 0;

				for (unsigned int i = 0; i < size; i++)
				{
					dot += data[i] * vec.data[i];
				}

				return dot;
			}

			float angle()
			{
				float angle = -atan(x / y);

				if (x > 0 && y < 0)
				{
					return angle;
				}

				angle += PI;

				if (x < 0 && y < 0)
				{
					angle += PI;
				}

				return angle;
			}

			friend std::ostream &operator<<(std::ostream &os, const Vec &vec)
			{
				std::stringstream output;

				for (int i = 0; i < max - 1; i++)
				{
					output << vec.data[i] << " ";
				}

				output << vec.data[max - 1];

				return os << output.str();
			}

			static const unsigned int size = max;
      
      union{
			T data[max] = {};
      struct{
			T x;
			T y;
      };};
	};
  
	template <typename T> class Vec<T, 3>
	{
    static const int max = 3;
		public:
			// \ Construct Vec with data starting all at 0
			Vec()
			{
			}

			// \ Construct Vec to be equal to vec
			// \ &vec - vec for data to be equal to
			Vec(Vec const &vec)
			{
				for (unsigned int i = 0; i < max; i++)
				{
					data[i] = vec.data[i];
				}
			}

			template <typename U, int amount> Vec(Vec<U, amount> const &vec)
			{
				unsigned int i;

				for (i = 0; (i < max) && (i < amount); i++)
				{
					data[i] = vec.data[i];
				}

				for (; i < max; i++)
				{
					data[i] = 0;
				}
			}

			// \ Construct Vec to xyzw values
			// \ x - X value
			// \ y - Y value
			// \ z - Z value
			// \ w - W value
			Vec(T x, T y, T z, T w)
			{
				this->x = x;
				this->y = y;
				this->z = z;
				this->w = w;
			}

			// \ Construct Vec to xyz values
			// \ x - X value
			// \ y - Y value
			// \ z - Z value
			Vec(T x, T y, T z)
			{
				this->x = x;
				this->y = y;
				this->z = z;
			}

			// \ Construct Vec to xy values
			// \ x - X value
			// \ y - Y value
			Vec(T x, T y)
			{
				this->x = x;
				this->y = y;
			}

			// \ Construct Vec to x value
			// \ x - X value
			Vec(T x)
			{
				this->x = x;
			}

			void operator=(Vec vec)
			{
				for (unsigned int i = 0; i < max; i++)
				{
					data[i] = vec.data[i];
				}
			}

			void operator+=(Vec vec)
			{
				for (unsigned int i = 0; i < max; i++)
				{
					data[i] += vec.data[i];
				}
			}

			void operator-=(Vec vec)
			{
				for (unsigned int i = 0; i < max; i++)
				{
					data[i] -= vec.data[i];
				}
			}

			void operator*=(T scale)
			{
				for (unsigned int i = 0; i < max; i++)
				{
					data[i] *= scale;
				}
			}

			void operator/=(T scale)
			{
				for (unsigned int i = 0; i < max; i++)
				{
					data[i] /= scale;
				}
			}

			Vec operator-(Vec vec)
			{
				Vec newVec;

				for (int i = 0; i < max; i++)
				{
					newVec.data[i] = data[i] - vec.data[i];
				}

				return newVec;
			}

			Vec operator+(Vec vec)
			{
				Vec newVec;

				for (int i = 0; i < max; i++)
				{
					newVec.data[i] = data[i] + vec.data[i];
				}

				return newVec;
			}

			Vec operator*(T scale)
			{
				Vec newVec;

				for (int i = 0; i < max; i++)
				{
					newVec.data[i] = data[i] * scale;
				}

				return newVec;
			}

			Vec operator/(T scale)
			{
				Vec newVec;

				for (int i = 0; i < max; i++)
				{
					newVec.data[i] = data[i] / scale;
				}

				return newVec;
			}

			// \ Get length of Vec
			T length()
			{
				return sqrt(this->dot(*this));
			}

			// \ Normalize Vec
			Vec normalized()
			{
				T len = this->length();
				return {x / len, y / len, z / len};
			}

			// \ Get the dot product of Vec and vec
			// \ vec - second vector
			float dot(Vec vec)
			{
				float dot = 0;

				for (unsigned int i = 0; i < size; i++)
				{
					dot += data[i] * vec.data[i];
				}

				return dot;
			}

			float angle()
			{
				float angle = -atan(x / y);

				if (x > 0 && y < 0)
				{
					return angle;
				}

				angle += PI;

				if (x < 0 && y < 0)
				{
					angle += PI;
				}

				return angle;
			}

			friend std::ostream &operator<<(std::ostream &os, const Vec &vec)
			{
				std::stringstream output;

				for (int i = 0; i < max - 1; i++)
				{
					output << vec.data[i] << " ";
				}

				output << vec.data[max - 1];

				return os << output.str();
			}

			static const unsigned int size = max;
      union{
          T data[max] = {};
          struct{
          T x;
          T y;
          T z;
          };};
	};
  
  template <typename T> class Vec<T, 4>
	{
    static const int max = 4;
		public:
			// \ Construct Vec with data starting all at 0
			Vec()
			{
			}

			// \ Construct Vec to be equal to vec
			// \ &vec - vec for data to be equal to
			Vec(Vec const &vec)
			{
				for (unsigned int i = 0; i < max; i++)
				{
					data[i] = vec.data[i];
				}
			}

			template <typename U, int amount> Vec(Vec<U, amount> const &vec)
			{
				unsigned int i;

				for (i = 0; (i < max) && (i < amount); i++)
				{
					data[i] = vec.data[i];
				}

				for (; i < max; i++)
				{
					data[i] = 0;
				}
			}

			// \ Construct Vec to xyzw values
			// \ x - X value
			// \ y - Y value
			// \ z - Z value
			// \ w - W value
			Vec(T x, T y, T z, T w)
			{
				this->x = x;
				this->y = y;
				this->z = z;
				this->w = w;
			}

			// \ Construct Vec to xyz values
			// \ x - X value
			// \ y - Y value
			// \ z - Z value
			Vec(T x, T y, T z)
			{
				this->x = x;
				this->y = y;
				this->z = z;
			}

			// \ Construct Vec to xy values
			// \ x - X value
			// \ y - Y value
			Vec(T x, T y)
			{
				this->x = x;
				this->y = y;
			}

			// \ Construct Vec to x value
			// \ x - X value
			Vec(T x)
			{
				this->x = x;
			}

			void operator=(Vec vec)
			{
				for (unsigned int i = 0; i < max; i++)
				{
					data[i] = vec.data[i];
				}
			}

			void operator+=(Vec vec)
			{
				for (unsigned int i = 0; i < max; i++)
				{
					data[i] += vec.data[i];
				}
			}

			void operator-=(Vec vec)
			{
				for (unsigned int i = 0; i < max; i++)
				{
					data[i] -= vec.data[i];
				}
			}

			void operator*=(T scale)
			{
				for (unsigned int i = 0; i < max; i++)
				{
					data[i] *= scale;
				}
			}

			void operator/=(T scale)
			{
				for (unsigned int i = 0; i < max; i++)
				{
					data[i] /= scale;
				}
			}

			Vec operator-(Vec vec)
			{
				Vec newVec;

				for (int i = 0; i < max; i++)
				{
					newVec.data[i] = data[i] - vec.data[i];
				}

				return newVec;
			}

			Vec operator+(Vec vec)
			{
				Vec newVec;

				for (int i = 0; i < max; i++)
				{
					newVec.data[i] = data[i] + vec.data[i];
				}

				return newVec;
			}

			Vec operator*(T scale)
			{
				Vec newVec;

				for (int i = 0; i < max; i++)
				{
					newVec.data[i] = data[i] * scale;
				}

				return newVec;
			}

			Vec operator/(T scale)
			{
				Vec newVec;

				for (int i = 0; i < max; i++)
				{
					newVec.data[i] = data[i] / scale;
				}

				return newVec;
			}

			// \ Get length of Vec
			T length()
			{
				return sqrt(this->dot(*this));
			}

			// \ Normalize Vec
			Vec normalized()
			{
				T len = this->length();
				return {x / len, y / len, z / len};
			}

			// \ Get the dot product of Vec and vec
			// \ vec - second vector
			float dot(Vec vec)
			{
				float dot = 0;

				for (unsigned int i = 0; i < size; i++)
				{
					dot += data[i] * vec.data[i];
				}

				return dot;
			}

			float angle()
			{
				float angle = -atan(x / y);

				if (x > 0 && y < 0)
				{
					return angle;
				}

				angle += PI;

				if (x < 0 && y < 0)
				{
					angle += PI;
				}

				return angle;
			}

			friend std::ostream &operator<<(std::ostream &os, const Vec &vec)
			{
				std::stringstream output;

				for (int i = 0; i < max - 1; i++)
				{
					output << vec.data[i] << " ";
				}

				output << vec.data[max - 1];

				return os << output.str();
			}

			const unsigned int size = max;

      
      union{
			T data[max] = {};
      struct{
			T x;
			T y;
			T z;
			T w;
      };};
	};
} // namespace agl
