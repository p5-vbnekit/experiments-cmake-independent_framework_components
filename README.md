# p5.experiments.cmake.framework_with_dedicated_components

An experimental example of a framework with dedicated components.
Each component (subproject) has no unnecessary dependencies.

- No unnecessary relationships between component and the parent project.
  - Only parent project knows about components (and not vice versa).
  - The component knows nothing about what it does not need.
    Component only knows about real dependencies.
    It doesn't know about parent project and unnecessary neighboring components (targets, etc).
    It has only explicit imported targets.
- Using the cmake export/import package mechanism for referencing dependencies (targets).
  Each component has unique namespace because only cmake export/import sections are sensitive.
- Each component (subprojects) can be built independently - no need to build with/from the parent project.
