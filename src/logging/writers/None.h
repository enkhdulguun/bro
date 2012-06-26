// See the file "COPYING" in the main distribution directory for copyright.
//
// Dummy log writer that just discards everything (but still pretends to rotate).

#ifndef LOGGING_WRITER_NONE_H
#define LOGGING_WRITER_NONE_H

#include "../WriterBackend.h"

namespace logging { namespace writer {

class None : public WriterBackend {
public:
	None(WriterFrontend* frontend) : WriterBackend(frontend)	{}
	~None()	{};

	static WriterBackend* Instantiate(WriterFrontend* frontend)
		{ return new None(frontend); }

protected:
	virtual bool DoInit(const WriterInfo& info, int num_fields,
			    const threading::Field* const * fields);

	virtual bool DoWrite(int num_fields, const threading::Field* const* fields,
			     threading::Value** vals)	{ return true; }
	virtual bool DoSetBuf(bool enabled)	{ return true; }
	virtual bool DoRotate(string rotated_path, const RotateInfo& info,
			      bool terminating);
	virtual bool DoFlush()	{ return true; }
	virtual bool DoFinish()	{ WriterBackend::DoFinish(); return true; }
};

}
}

#endif
