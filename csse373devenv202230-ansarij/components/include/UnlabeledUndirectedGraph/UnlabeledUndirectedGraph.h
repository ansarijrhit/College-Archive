#pragma once

#include "UnlabeledUndirectedGraph/UnlabeledUndirectedGraph0.hpp"

#ifdef _DEBUG
#include "UnlabeledUndirectedGraph/UnlabeledUndirectedGraphChecking1.hpp"
typedef UnlabeledUndirectedGraphChecking<UnlabeledUndirectedGraph0> UnlabeledUndirectedGraph;
#else
// Use typedef to create generic name 
// That is, a name w/o the vesion # at the end
typedef UnlabeledUndirectedGraph0 UnlabeledUndirectedGraph;
#endif