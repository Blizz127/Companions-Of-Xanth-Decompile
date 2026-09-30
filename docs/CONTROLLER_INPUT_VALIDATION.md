# Controller guest UI validation

The guest UI reader accepts DGROUP from the shared read-only state observer.
It reads current region tables for each action and never writes guest memory.
It reproduces the retail hit test, including signed-word polygon arithmetic
and the precedence of overlapping regions. Snap points must resolve to the
same live record. Unsupported or malformed layouts decline the action.

Verb rows come from the live lists and font height. Every emitted point must
hit its actual verb panel. The inclusive panel bottom is not an extra row.
Cycling moves the normal guest pointer; it does not patch the selected verb.
The retail letter shortcuts have their own behavior and are tested separately.

Validation used the owner's loaded executable, not committed retail fixtures:
5,120 live screen points and 22,500 generated polygon points matched the guest
routines. Seven standard and two context rows matched live IDs and highlights.
The synthetic tests also cover overlap, occlusion, disabled regions, pointer
bounds, list termination, and unchanged guest memory.

Build and run with owned data outside the checkout:

```sh
cmake -S port -B build -DXANTH_TEST_DATA_DIR=/path/to/owned/data
cmake --build build -j2
ctest --test-dir build -R 'ControllerGuestUiTests|GuestVerbSemanticsTests|Vm_mzload' --output-on-failure
```

Screenshots and complete memory snapshots used during investigation are private
scratch evidence. They are not source fixtures or release assets. The helper
alone does not enable controller actions; integration requires the shared
observer to distinguish idle field input from dialogs and command execution.
