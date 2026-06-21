#ifndef LL_PARALLELOGRAM_H
#define LL_PARALLELOGRAM_H

#include "Parallelogram.h"
#include <string>

class LL_Parallelogram : public Parallelogram {
public:
    LL_Parallelogram(int width, int height, const std::string& name = "LL Box");
	virtual ~LL_Parallelogram () = default;
	
	Canvas draw(char pen = '*', char fillChar=' ') override;
};

#endif
