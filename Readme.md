# summary

This is a (probable) bug reproduction  for Visual Studio CMake+Gtest integration.

Steps:

1. Open as folder in Visual Studio (used 15.9.3 Preview 1.0)
2. `CMake | Build All`
3. Run tests via `CMake | Tests | Run cmake-vc-bug CTests`
 
   Output shows:

   ```
        Start 1: tests
    1/1 Test #1: tests ............................   Passed    0.01 sec

    100% tests passed, 0 tests failed out of 1
   ```

   This is correct behavior, as we set LD_LIBRARY_PATH to specific value and check for that in test (to see if it was passed to the executable).
  
4. Run tests via `Test Explorer`, `"Run All"` button:

   Sample test fails with
   ```
       Message: 
    Expected equality of these values:
      std::getenv("LD_LIBRARY_PATH")
        Which is: NULL
      "my-custom-library-path"

   ```

   Expected result is that environment variables are respected. This is extremely important when test executable links to external libraries and fails to even list tests if incorrect environment setup is provided.