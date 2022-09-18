function [str] = val2str( arg )
    if isempty( arg )
		str = '[]';
		return;
    end
    
    if ischar( arg )
        str = mat2str( arg );
        return;
    end
		
    sz = size( arg );
    rows = sz(1);
    cols = sz(2);
    cnt = rows * cols;

    if isstruct( arg )
        if cnt <= 1
            % scalar structure
            fields = fieldnames( arg );
            if length(fields) <= 0
                str = 'struct';
                return;
            else
                s = '';
                d = 'struct( ';
                for i = 1 : length(fields)
                    s = [ s d '''' fields{i} ''', ' val2str( arg.(fields{i}) ) ];
                    d = ', ';
                end
                str = [ s ' )' ];
                return;
            end
        elseif rows <= 1
            % row-vector of structures
            s = '';
            d = '[ ';
            for i=1 : cols
                s = [ s d val2str( arg(i) ) ];
                d = ', ';
            end
            str = [ s ' ]' ];
            return;
        else
            % 2D array of structures
            s = '';
            r = '[ ';
            for j=1 : rows
                d = '';
                for i=1 : cols
                    s = [ s r d val2str( arg(j,i) ) ];
                    r = '';
                    d = ', ';
                end
                r = sprintf('; ...\n');
            end
            str = [ s ' ]' ];
            return;
        end
    end

    if iscell( arg )
        if cnt <= 0
            % empty cell
            str = '{}';
            return;
        elseif rows <= 1
            % row-vector
            s = '';
            d = '{ ';
            for i=1 : cols
                s = [ s d val2str( arg{i} ) ];
                d = ' ';
            end
            str = [ s ' }' ];
            return;
        else
            % 2D cell array
            s = '';
            r = '{ ';
            for j=1 : rows
                d = '';
                for i=1 : cols
                    s = [ s r d val2str( arg{j,i} ) ];
                    r = '';
                    d = ' ';
                end
                r = sprintf('; ...\n');
            end
            str = [ s ' }' ];
            return;
        end
    end

    if 2 < ndims( arg )
        str = sprintf( 'reshape( %s, %s )', mat2str( arg(:) ), mat2str( size(arg) ) );
    else
        str = mat2str( arg );    
    end
end
