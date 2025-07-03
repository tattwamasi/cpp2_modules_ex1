module;

#define CPP2_IMPORT_STD Yes

#include "cpp2util.h"

export module Example;
namespace Example_NS {}

#define ANSWER 42

namespace Example_NS {
[[nodiscard]] auto f_internal() -> int;

export [[nodiscard]] auto f(void) -> int;

} // namespace Example_NS

int f2() { return 43; }

namespace Example_NS {
[[nodiscard]] auto f_internal() -> int { return ANSWER; }

[[nodiscard]] auto f() -> int { return f_internal(); }

} // namespace Example_NS