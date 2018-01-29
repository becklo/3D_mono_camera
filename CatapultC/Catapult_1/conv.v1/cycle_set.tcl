
# Loop constraints
directive set /conv/core/core:rlp CSTEPS_FROM {{. == 0}}
directive set /conv/core/core:rlp/main CSTEPS_FROM {{. == 2} {.. == 0}}
directive set /conv/core/core:rlp/main/for CSTEPS_FROM {{. == 1} {.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for CSTEPS_FROM {{. == 3} {.. == 0}}

# IO operation constraints

# Sync operation constraints

# Real operation constraints
directive set /conv/core/core:rlp/main/for/for:for/for:for:mul#1 CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:for:for:acc#1 CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:read_mem(image_in:rsc.@) CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:acc#4 CSTEPS_FROM {{.. == 2}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:write_mem(image_out:rsc.@) CSTEPS_FROM {{.. == 2}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:acc#3 CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:for/for:for:acc CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:acc#1 CSTEPS_FROM {{.. == 1}}
directive set /conv/core/core:rlp/main/for/for:acc CSTEPS_FROM {{.. == 1}}

# Probe constraints
