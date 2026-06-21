#ifndef RL_PARALLELOGRAM_H
#define RL_PARALLELOGRAM_H

#include "Parallelogram.h"
#include <string>

class RL_Parallelogram : public Parallelogram {
public:
    RL_Parallelogram(int width, int height, const std::string& name = "RL Box");
	virtual ~RL_Parallelogram () = default;

	Canvas draw(char pen = '*', char fillChar=' ') override;
};

#endif