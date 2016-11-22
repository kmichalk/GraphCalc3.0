#include "AnalizerComponent.h"

AnalizerComponent::AnalizerComponent(CommandAnalizer & parentAnalizer)
	:
	parentAnalizer{parentAnalizer}
{
}

AnalizerComponent::~AnalizerComponent()
{
}
