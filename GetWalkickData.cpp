#include <vector>

#include "Global.hpp"
#include "GetWalkickData.hpp"

std::vector<Position> get_wall_kick_data(bool i_is_i_shape, unsigned char i_current_rotation, unsigned char i_next_rotation)
{
	

	if (0 == i_is_i_shape)
	{
		switch (i_current_rotation)
		{
			case 0:
			case 2:
			{
				switch (i_next_rotation)
				{
					case 1:
					{
						return {{0, 0}, {-1, 0}, {-1, -1}, {0, 2}, {-1, 2}};
					}
					case 3:
					{
						return {{0, 0}, {1, 0}, {1, -1}, {0, 2}, {1, 2}};
					}
				}
			}
			case 1:
			{
				return {{0, 0}, {1, 0}, {1, 1}, {0, -2}, {1, -2}};
			}
			case 3:
			{
				return {{0, 0}, {-1, 0}, {-1, 1}, {0, -2}, {-1, -2}};
			}
		}

		return {{0, 0}};
	}
	else
	{
		switch (i_current_rotation)
		{
			case 0:
			{
				switch (i_next_rotation)
				{
					case 1:
					{
						return {{0, 0}, {-2, 0}, {1, 0}, {-2, 1}, {1, -2}};
					}
					case 3:
					{
						return {{0, 0}, {-1, 0}, {2, 0}, {-1, -2}, {2, 1}};
					}
				}
			}
			case 1:
			{
				switch (i_next_rotation)
				{
					case 0:
					{
						return {{0, 0}, {2, 0}, {-1, 0}, {2, -1}, {-1, 2}};
					}
					case 2:
					{
						return {{0, 0}, {-1, 0}, {2, 0}, {-1, -2}, {2, 1}};
					}
				}
			}
			case 2:
			{
				switch (i_next_rotation)
				{
					case 1:
					{
						return {{0, 0}, {1, 0}, {-2, 0}, {1, 2}, {-2, -1}};
					}
					case 3:
					{
						return {{0, 0}, {2, 0}, {-1, 0}, {2, -1}, {-1, 2}};
					}
				}
			}
			case 3:
			{
				switch (i_next_rotation)
				{
					case 0:
					{
						return {{0, 0}, {1, 0}, {-2, 0}, {1, 2}, {-2, -1}};
					}
					case 2:
					{
						return {{0, 0}, {-2, 0}, {1, 0}, {-2, 1}, {1, -2}};
					}
				}
			}
		}

		return {{0, 0}};
	}
}