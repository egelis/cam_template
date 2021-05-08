#include "fake.h"

FakeCamera::FakeCamera(Metadata descr)
{
    this->meta = descr;
}

Frame FakeCamera::getNewFrame()
{
    // TODO: generate
    return {};
}
