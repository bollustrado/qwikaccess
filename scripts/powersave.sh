#!/bin/sh
    gov=powersave
    if [ -n "$gov" ]; then
        for cpu in /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor; do
            printf '%s\n' "$gov" > $cpu; 2> /dev/null
        done
    fi


    energyperf=power
    if [ -n "$energyperf" ]; then
        if [ -f /sys/devices/system/cpu/cpu0/cpufreq/energy_performance_preference ]; then
            for cpu in /sys/devices/system/cpu/cpu*/cpufreq/energy_performance_preference; do
                printf '%s\n' "$energyperf" > $cpu; 2> /dev/null
            done
        else
            pnum=$(echo $energyperf | sed -r 's/^performance$/0/;
                                s/^balance_performance$/4/;
                                s/^(default|normal)$/6/;
                                s/^balance_power?$/8/;
                                s/^power(save)?$/15/')

            x86_energy_perf_policy $pnum > /dev/null 2>&1
        fi
    fi



    nvidia-settings -a "[gpu:0]/GpuPowerMizerMode=2" 2> /dev/null
    echo battery > /sys/class/drm/card0/device/power_dpm_state
    echo low > /sys/class/drm/card0/device/power_dpm_force_performance_level
    echo powersave > /sys/module/pcie_aspm/parameters/policy
    echo 1 > /sys/devices/system/cpu/intel_pstate/no_turbo
    echo 0 > /sys/devices/system/cpu/cpufreq/boost
