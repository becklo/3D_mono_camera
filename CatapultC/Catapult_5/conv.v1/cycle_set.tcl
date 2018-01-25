
# Loop constraints
directive set /conv/core/core:rlp CSTEPS_FROM {{. == 0}}
directive set /conv/core/core:rlp/main CSTEPS_FROM {{. == 2} {.. == 0}}
directive set /conv/core/core:rlp/main/for CSTEPS_FROM {{. == 2} {.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for CSTEPS_FROM {{. == 1} {.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for CSTEPS_FROM {{. == 2} {.. == 0}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for CSTEPS_FROM {{. == 4} {.. == 1}}

# IO operation constraints
directive set /conv/core/core:rlp/main/rows:io_read(rows:rsc.@) CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/cols:io_read(cols:rsc.@) CSTEPS_FROM {{.. == 1}}

# Sync operation constraints

# Real operation constraints
directive set /conv/core/core:rlp/main/for:acc#2 CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for:acc#2 CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:acc#1 CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for/for:for:for:for:acc#12 CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for/for:for:for:for:acc#3 CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for/for:for:for:for:acc#13 CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for/for:for:for:for:acc#5 CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for/for:for:for:for:aif:acc CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for/for:for:for:for:aif#2:acc CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for/for:for:for:for:if:mul CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for/for:for:for:for:if:acc CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for/for:for:for:for:if:read_mem(sortie:rsc.@) CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for/for:for:for:for:if:mul#1 CSTEPS_FROM {{.. == 2}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for/for:for:for:for:if:acc#3 CSTEPS_FROM {{.. == 2}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for/for:for:for:for:if:read_mem(image:rsc.@) CSTEPS_FROM {{.. == 2}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for/for:for:for:for:acc#14 CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for/for:for:for:for:acc#15 CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for/for:for:for:for:acc#11 CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for/for:for:for:for:if:read_mem(kernel:rsc.@) CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for/for:for:for:for:if:mul#3 CSTEPS_FROM {{.. == 3}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for/for:for:for:for:if:for:for:for:for:if:acc#3 CSTEPS_FROM {{.. == 3}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for/for:for:for:for:if:write_mem(sortie:rsc.@) CSTEPS_FROM {{.. == 3}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for/for:for:for:for:acc#8 CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:for/for:for:for:for:acc CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:acc#3 CSTEPS_FROM {{.. == 2}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for/for:for:for:acc CSTEPS_FROM {{.. == 2}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:acc#1 CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:acc CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:acc#1 CSTEPS_FROM {{.. == 2}}
directive set /conv/core/core:rlp/main/for/for:acc CSTEPS_FROM {{.. == 2}}

# Probe constraints
