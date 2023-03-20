/* interchange two arguments of type t */

#define swap(t, x, y) \
{\
	t temp = x;\
	x = y;\
	y = temp;\
}
