
# Loop constraints
directive set /main/core/core:rlp CSTEPS_FROM {{. == 0}}
directive set /main/core/core:rlp/main CSTEPS_FROM {{. == 2} {.. == 0}}
directive set /main/core/core:rlp/main/for CSTEPS_FROM {{. == 1} {.. == 1}}
directive set /main/core/core:rlp/main/for/for:for CSTEPS_FROM {{. == 3} {.. == 0}}
directive set /main/core/core:rlp/main/for#1 CSTEPS_FROM {{. == 1} {.. == 1}}
directive set /main/core/core:rlp/main/for#1/for#1:for CSTEPS_FROM {{. == 3} {.. == 0}}
directive set /main/core/core:rlp/main/for#1/for#1:for/reconstruction_error:for CSTEPS_FROM {{. == 2} {.. == 1}}
directive set /main/core/core:rlp/main/for#1/for#1:for/reconstruction_error:for/reconstruction_error:for:for CSTEPS_FROM {{. == 2} {.. == 1}}

# IO operation constraints
directive set /main/core/core:rlp/main/io_write(return:rsc.@) CSTEPS_FROM {{.. == 1}}

# Sync operation constraints

# Real operation constraints
directive set /main/core/core:rlp/main/for/for:for/for:for:if:acc#1 CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for/for:for/for:for:oif:acc CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for/for:for/for:for:aelse:acc CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for/for:for/for:for:aif:oif:acc CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for/for:for/for:for:if:mul CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for/for:for/for:for:if:acc CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for/for:for/for:for:if:write_mem(image_error:rsc.@) CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for/for:for/for:for:else:mul#1 CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for/for:for/for:for:else:acc#3 CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for/for:for/for:for:else:read_mem(image_floue:rsc.@) CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for/for:for/for:for:else:read_mem(image_net:rsc.@) CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for/for:for/for:for:else:for:for:else:acc#3 CSTEPS_FROM {{.. == 2}}
directive set /main/core/core:rlp/main/for/for:for/for:for:else:acc CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for/for:for/for:for:else:write_mem(image_error:rsc.@) CSTEPS_FROM {{.. == 2}}
directive set /main/core/core:rlp/main/for/for:for/for:for:acc#2 CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for/for:for/for:for:acc CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for/for:acc#1 CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for/for:acc CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for#1/for#1:for/for#1:for:acc#6 CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for#1/for#1:for/for#1:for:acc#7 CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for#1/for#1:for/reconstruction_error:for:l:acc CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for#1/for#1:for/reconstruction_error:for:acc#4 CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for#1/for#1:for/reconstruction_error:for:acc#3 CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for#1/for#1:for/reconstruction_error:for/reconstruction_error:for:for:c:acc CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for#1/for#1:for/reconstruction_error:for/reconstruction_error:for:for:acc#8 CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for#1/for#1:for/reconstruction_error:for/reconstruction_error:for:for:acc#7 CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for#1/for#1:for/reconstruction_error:for/reconstruction_error:for:for/reconstruction_error:for:for:mul CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for#1/for#1:for/reconstruction_error:for/reconstruction_error:for:for/reconstruction_error:for:for:acc#6 CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for#1/for#1:for/reconstruction_error:for/reconstruction_error:for:for/reconstruction_error:for:for:read_mem(image_error:rsc.@) CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for#1/for#1:for/reconstruction_error:for/reconstruction_error:for:for/reconstruction_error:for:for:acc#5 CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for#1/for#1:for/reconstruction_error:for/reconstruction_error:for:for/reconstruction_error:for:for:mul#2 CSTEPS_FROM {{.. == 2}}
directive set /main/core/core:rlp/main/for#1/for#1:for/reconstruction_error:for/reconstruction_error:for:for/reconstruction_error:for:for:acc#4 CSTEPS_FROM {{.. == 2}}
directive set /main/core/core:rlp/main/for#1/for#1:for/reconstruction_error:for/reconstruction_error:for:for/reconstruction_error:for:for:acc#9 CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for#1/for#1:for/reconstruction_error:for/reconstruction_error:for:for/reconstruction_error:for:for:acc CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for#1/for#1:for/reconstruction_error:for/reconstruction_error:for:acc#2 CSTEPS_FROM {{.. == 2}}
directive set /main/core/core:rlp/main/for#1/for#1:for/reconstruction_error:for/reconstruction_error:for:acc#5 CSTEPS_FROM {{.. == 2}}
directive set /main/core/core:rlp/main/for#1/for#1:for/reconstruction_error:for/reconstruction_error:for:acc CSTEPS_FROM {{.. == 2}}
directive set /main/core/core:rlp/main/for#1/for#1:for/reconstruction_error:acc CSTEPS_FROM {{.. == 2}}
directive set /main/core/core:rlp/main/for#1/for#1:for/reconstruction_error:mux CSTEPS_FROM {{.. == 2}}
directive set /main/core/core:rlp/main/for#1/for#1:for/for#1:for:mul CSTEPS_FROM {{.. == 2}}
directive set /main/core/core:rlp/main/for#1/for#1:for/for#1:for:acc#5 CSTEPS_FROM {{.. == 2}}
directive set /main/core/core:rlp/main/for#1/for#1:for/for#1:for:write_mem(depth:rsc.@) CSTEPS_FROM {{.. == 2}}
directive set /main/core/core:rlp/main/for#1/for#1:for/for#1:for:acc#4 CSTEPS_FROM {{.. == 2}}
directive set /main/core/core:rlp/main/for#1/for#1:for/for#1:for:acc CSTEPS_FROM {{.. == 2}}
directive set /main/core/core:rlp/main/for#1/for#1:acc#1 CSTEPS_FROM {{.. == 1}}
directive set /main/core/core:rlp/main/for#1/for#1:acc CSTEPS_FROM {{.. == 1}}

# Probe constraints
