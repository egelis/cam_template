#include "fake.h"

FakeCamera::FakeCamera(const Metadata &desc)
{
    this->meta = desc;
}

Frame FakeCamera::getNewFrame()
{
    // TODO: generate
    return {};
}

void FakeCamera::init() {

}
