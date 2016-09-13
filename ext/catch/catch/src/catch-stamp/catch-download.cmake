

set(command "/usr/bin/cmake;-P;/home/aluno/Downloads/cppframes/ext/catch/catch/tmp/catch-gitclone.cmake")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/aluno/Downloads/cppframes/ext/catch/catch/src/catch-stamp/catch-download-out.log"
  ERROR_FILE "/home/aluno/Downloads/cppframes/ext/catch/catch/src/catch-stamp/catch-download-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/aluno/Downloads/cppframes/ext/catch/catch/src/catch-stamp/catch-download-*.log\n")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "catch download command succeeded.  See also /home/aluno/Downloads/cppframes/ext/catch/catch/src/catch-stamp/catch-download-*.log\n")
  message(STATUS "${msg}")
endif()
