function lookupArgPair(map, array) 
    local ret = true

    if (array) then
        ret = {}
    end

    for k, v in pairs(map) do
           if (_OPTIONS[k] ~= nil) then
               if (array) then
                   table.insert(ret, v)
               else
                   return v
               end
        end
    end
    
    return ret
end


return lookupArgPair